/*
 *
 *		The Poleaxe Graphics and Windowing system.
 *
 * Jeff Shoulders and Robert Butler
 * hx86 working group
 * loliniel@gmail.com
 * lighth7015@gmail.com
 *
 *	(c) 2010
 *
 */


#include "../../poleaxe.h"


config::config()
{
	doc = new TiXmlDocument(CONFIG_FILE);
	LoadConfigurationFile();
}


config::config(string _config_file)
{
	doc = new TiXmlDocument(_config_file.c_str());
	LoadConfigurationFile();
}


config::~config()
{
}


string config::ConfigurationFile()
{
    return "";
}


void config::ConfigurationFile(string _config_file)
{
}


bool config::LoadConfigurationFile()
{
	bool load_test;

	//test to see if the doc file is ready... todo
	load_test = doc->LoadFile();
	if(load_test != true)
	{
		LogMessage("Error loading the configuration.");
		return false;
	}
	else
		return true;

	return false;
}


typedef boost::shared_ptr<config> Config;

//string											ConfigValue(string _name);
//void											ConfigValue(string);
