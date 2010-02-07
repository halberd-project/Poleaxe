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

#ifndef __CONFIG__
#define __CONFIG__


#include "../../poleaxe.h"


//standard config file which contains information about the UI and the poleaxe system as a whole.
#define CONFIG_FILE									"config.xml"


//Device Capabilities structure.
typedef struct Caps
{
	string name;
	string value;
} Caps;


typedef struct Element
{
	string name;
	string value;
	int num_attr;
	string *attr;
} Element;


class config : public object
{
	protected:
		string 									filename;
		TiXmlDocument 							*doc;
		Element									*elements;
		int 									num_elements;

	public:
		config();
		config(string _config_file);
		~config();
		//retrieve and alter the configuration file.
		string									ConfigurationFile();
		void 									ConfigurationFile(string _config_file);
		bool 									LoadConfigurationFile();
		int										NumberOfElements();
		int										NumberOfAttributes(string element);
		string									Attribute(string element, string attr);
};


typedef boost::shared_ptr<config> Config;

//string											ConfigValue(string _name);
//void											ConfigValue(string);



#endif		//__CONFIG__
