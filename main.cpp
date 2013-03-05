#include "xmppclient.h"
#include <boost/program_options.hpp>
#include <string>
#include <iostream>

using namespace std;
namespace po = boost::program_options;

int main(int ac, char** av)
{
	// Declare the supported options.
	po::options_description desc("options");
	desc.add_options()
	    ("help,h", "produce help message")
	    ("user,u", po::value<string>(), "the jid to login")
	    ("password,p", po::value<string>(), "the password")
	    ("nickname,n", po::value<string>(), "the nickname you'd like to set")
//	    ("data,d", po::value<string>(), "the stanza to send after login")
	;

	po::variables_map vm;
	po::store(po::parse_command_line(ac, av, desc), vm);
//	po::store(po::parse_config_file("xmppc.cfg", desc), vm);
	po::notify(vm);

	if (vm.count("help")) {
	    cout << desc << "\n";
	    return 0;
	}

	if (vm.count("user") == 0 || vm.count("password") == 0) 
	{
	    cout << desc << "\nYou have to specify username and password\n\n";
	    return 1;
	}

	string jid = vm["user"].as<string>(),
		password = vm["password"].as<string>(),
		nickname;

	if (vm.count("nickname"))
		nickname = vm["nickname"].as<string>();


	cout << "Login with " << jid << endl;

	XmppClient *r = new XmppClient(jid, password);
	r->set_nickname(nickname);
	r->start();
	delete( r );
	return 0;
}