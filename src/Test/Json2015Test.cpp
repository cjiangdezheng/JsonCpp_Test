// Json2015Test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include <string>
#include "json/json.h"


using namespace std;

int main()
{
////////////////////////////////////////////////////////////////////////////////////
//
//封装
//
////////////////////////////////////////////////////////////////////////////////////
	Json::Value json_temp;
	json_temp["name"] = Json::Value("jiang");
	json_temp["age"] = Json::Value(30);

	Json::Value root;
	root["key_string"] = Json::Value("value_string");
	root["key_number"] = Json::Value(12345);
	root["key_boolean"] = Json::Value(false);
	root["key_double"] = Json::Value(12.345);
	root["key_object"] = json_temp;
	root["key_array"].append("array_string");
	root["key_array"].append(1234);

	Json::ValueType type = root.type();
	string str = root.toStyledString();
	cout << str << endl;

////////////////////////////////////////////////////////////////////////////////////
//
//解析
//
////////////////////////////////////////////////////////////////////////////////////
	Json::Reader reader;
	Json::Value json_object;

	if (!reader.parse(str, json_object))
		return 0;
	if (json_object["key_string"].isString())
	{
		string key_string = json_object["key_string"].asString();
		cout << key_string << endl;
	}
	if (json_object["key_number"].isInt())
	{
		int key_number = json_object["key_number"].asInt();
		cout << key_number << endl;
	}
	if (json_object["key_boolean"].isBool())
	{
		bool key_boolean = json_object["key_boolean"].asBool();
		cout << key_boolean << endl;
	}
	if (json_object["key_double"].isDouble())
	{
		double key_double = json_object["key_double"].asDouble();
		cout << key_double << endl;
	}
	if (json_object["key_object"].isObject())
	{
		if (json_object["key_object"]["name"].isString() && json_object["key_object"].isMember("name")) //双判断
		{
			string name = json_object["key_object"]["name"].asString();
			cout << name << endl;
		}
		if (json_object["key_object"]["age"].isInt())
		{
			int age = json_object["key_object"]["age"].asInt();
			cout << age << endl;
		}
	}
	if (json_object["key_array"].isArray())
	{
		int size = json_object["key_array"].size();
		cout << "数组大小为：" << size << endl;
		if (json_object["key_array"][0].isString())
		{
			string key_array1 = json_object["key_array"][0].asString();
			cout << key_array1 << endl;
		}
		if (json_object["key_array"][1].isInt())
		{
			int key_array2 = json_object["key_array"][1].asInt();
			cout << key_array2 << endl;
		}
	}
	
	
	
////////////////////////////////////////////////////////////////////////////////////
//
//打印
//
////////////////////////////////////////////////////////////////////////////////////
/*	//Json::FastWriter writer;  
	Json::StyledWriter writer; 
	string strPrint = writer.write(root);
	cout << strPrint << endl;
*/
    return 0;
}

