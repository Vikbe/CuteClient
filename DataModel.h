#pragma once

#include <boost/serialization/vector.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <string> 
#include <sstream>

struct DataModel
{
	std::string Date;
	long long Id;
	std::string Number;
	double Constant;
	int Digits;
	int Decimals;

	template <class Archive>
	void serialize(Archive& ar, unsigned int version)
	{
		ar & Date;
		ar & Id;
		ar & Number;
		ar & Constant;
		ar & Digits;
		ar & Decimals;
	}  

	DataModel() {} 

	// Format as string for QT listview
	std::string AsString()
	{
		std::ostringstream oss; 
		oss << Date << "        " << Id << "                  " << Number <<  
			"              " << Constant << "                  "  
			<< Digits << "                      " << Decimals; 
		
		return oss.str();
	}
}; 

struct SearchModel
{
	std::string Date;
	std::string Id;
	std::string Number;
	std::string Constant;
	std::string Digits;
	std::string Decimals;

	template <class Archive>
	void serialize(Archive& ar, unsigned int version)
	{
		ar & Date;
		ar & Id;
		ar & Number;
		ar & Constant;
		ar & Digits;
		ar & Decimals;
	}
};

struct QueryData
{
	std::vector<DataModel> QueryResult;

	void AddData(const DataModel& row)
	{
		QueryResult.push_back(row);
	} 

	bool IsValid()
	{
		return !QueryResult.empty();
	}

	template <class Archive>
	void serialize(Archive& ar, unsigned int version)
	{
		ar & QueryResult;
	}
};