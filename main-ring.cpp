#include "devcore/easylogging++.h"
#include "algorithm/RingSig.h"
#include <iostream>
INITIALIZE_EASYLOGGINGPP;
using namespace RingSigApi::LinkableRingSig;
int main()
{
	std::string ring_param;
	/*
	int bit_len=256;
	int flag=setup_ring(ring_param,bit_len);
	LinkableRingSigParam param;
	param.init_param(ring_param);
	param.store_param(ring_param);
	std::cout<<ring_param;
	*/
	LinkableRingSignature lrs;
	LinkableRingSigImpl lrsi;
	LinkableRingSigPrivatekeys lrspk;
	lrsi.setup_ring(ring_param);
	std::string private_key;
	std::string public_key;
	vector<std::string>public_key_list;
	vector<LinkableRingSigPrivatekeys> private_key_list;
	int num=3;
	for(int i=0;i<num;i++)
	{
		string n=to_string(i);
		std::cout<<"n="<<n<<"\n";
		lrsi.join_ring(private_key,public_key,ring_param,n);
		public_key_list.push_back(public_key);
		lrspk.load_private_key(private_key);
		private_key_list.push_back(lrspk);
		std::cout<<"private_key="<<private_key<<"\n";
		std::cout<<"public_key="<<public_key<<"\n";
	}
	string sig_info;
	//lrs.store_sig(sig_info,public_key_list,2);
	private_key_list[2].store_private_key(private_key);
	std::cout<<"private_key="<<private_key<<"\n";
	lrsi.linkable_ring_sig(sig_info,"i am fool!",public_key_list,private_key,ring_param);
	bool valid=true;
	lrsi.linkable_ring_verify(valid,sig_info,"i am fool!",ring_param);
	std::cout<<"sig_info="<<sig_info<<"\n";
	std::cout<<"valid="<<valid<<"\n";
	vector<string> deprive_private_keys;
	for(int i=0;i<num;i++)
	{
		private_key_list[i].store_private_key(private_key);
		JsonConfigParser json(private_key,JsonString);
		string prk_x="prk_x";
		string pk=json.get_value<string>(prk_x);
		deprive_private_keys.push_back(pk);
	}
	std::cout<<"private_keys=";
	for(int i=0;i<num;i++)
	{
		std::cout<<deprive_private_keys[i]<<",";
	}
	std::cout<<"\n";
	std::cout<<"public_keys=";
	for(int i=0;i<num;i++)
	{
		std::cout<<public_key_list[i]<<",";
	}

	std::cout<<"\n";

	JsonConfigParser json(ring_param,JsonString);
	std::string g=json.get_value<string>("g");
	std::string p=json.get_value<string>("p");
	std::string q=json.get_value<string>("q");
	std::cout<<"g="<<g<<"\n";
	std::cout<<"p="<<p<<"\n";
	std::cout<<"q="<<q<<"\n";

	return 0;
}
