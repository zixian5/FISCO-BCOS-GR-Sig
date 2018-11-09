/*
 * main.cpp
 *
 *  Created on: Nov 8, 2018
 *      Author: wzx
 */
#include "algorithm/GroupSig.h"
#include "devcore/CommonFunc.h"
#include "devcore/easylogging++.h"
#include <iostream>
INITIALIZE_EASYLOGGINGPP;

using namespace std;
using namespace GroupSigApi;

int main()
{
	//generate gpk, gmsk for group specified by group_name

	const string group_name = "test";
	const string gmsk_pass = "wwzz"; //manager's password
	const string algorithm_method = "bbs04"; //the only choice
    string pbc_param="{\"linear_type\":\"a\", \"q_bits_len\": 256, \"r_bits_len\":256}";//an example of parameter

	string gpk_info;
	string prefix = "group "+ group_name;
	string result;

	int internal_ret = create_group(result , algorithm_method ,pbc_param);
	vector<string> result_vec = dev::eth::split(result, dev::eth::BBSGroupSig::RET_DELIM);
	   //vector[0]: gpk --return and store
	   //vector[1]: gmsk --store
	   //vector[2]: gamma --store
	   //vector[3]: pbc_param --store
	const string gmsk = result_vec[1];//group manager's psk
	const string gpk = result_vec[0];//group's pbk
	const string gamma = result_vec[2];// gamma information, a secert number
	pbc_param = result_vec[3];

	cout<<"pbc_param:"<<pbc_param<<endl;
	cout<<"gmsk:"<<gmsk<<endl;

	vector<string> gsk_info_list;

	//群成员加入群，群主为其产生私钥和证书
	int nums=3;
	for(int i=0;i<nums;i++)
	{
		string gsk_info;
		group_member_join(gsk_info,algorithm_method,
					pbc_param,gmsk,gpk,gamma);
		gsk_info_list.push_back(gsk_info);
		cout<<"member"<<i<<"'s"<<gsk_info<<endl;
	}

	//对明文信息message进行群签名
	string sign;
	string message = "gogohurry";
	int ret = group_sig(sign,algorithm_method,
				gpk,gsk_info_list[0],pbc_param,message);
	cout<<"sign:"<<sign;

	//群签名验证
	int is_valid;
	internal_ret = group_verify(is_valid, sign,
	            message, algorithm_method, gpk, pbc_param);
	if(is_valid == 1)
	{
		cout<<"SUCCESS"<<endl;
	}
	else
	{
		cout<<"FALSE"<<endl;
	}

	//群主获取指定签名的签名者证书
	string cert;
	open_cert(cert, algorithm_method, sign, message, gpk, gmsk,pbc_param);
	cout<<"cert:"<<cert<<endl;
	return 0;
}
