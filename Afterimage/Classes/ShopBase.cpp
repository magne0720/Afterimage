#include "ShopBase.h"

ShopBase* ShopBase::create(int kind)
{
	ShopBase *pRet = new ShopBase();
	if (pRet && pRet->init(kind))
	{
		pRet->autorelease();
		return pRet;
	}
	else
	{
		delete pRet;
		pRet = nullptr;
		return nullptr;
	}
};

bool ShopBase::init(int kind)
{
	if(!Sprite::init())
	{
		return false;
	}
	log("ShopBase=%d", kind);

	String* name = String::createWithFormat("building_%d.png", kind);

	initWithFile(name->getCString());
	log("%s", name->getCString());

	ShopCreate(kind);

	return true;
};

void ShopBase::update(float delta)
{



};

void ShopBase::ShopCreate(int kind)
{
	auto split = [](const std::string& input, char delimiter)
	{
		istringstream stream(input);
		string field;
		vector<string> result;
		while (std::getline(stream, field, delimiter))
		{
			result.push_back(field);
		}
		return result;
	};

	String* filename = String::createWithFormat("Shop/ShopData.txt");

	string fileText = FileUtils::getInstance()->getStringFromFile(filename->getCString());

	vector<string> lines = split(fileText, '\n');
	vector<string> datas = split(lines[kind], ',');
	
	int temp = 0;

	for (int i = 0; i < datas.size(); i++)
	{
		//‚±‚±‚Éˆ—
		char data = datas[i][0];

#define LINE_OPEN datas[i].c_str()

		switch (data)
		{
		case 'N'://name
			i++;
			shopStatus.name = LINE_OPEN;
			break;
		case 'G'://gate
			i++;
			shopStatus.gate = atof(LINE_OPEN);
			break;
		case 'S'://status
			i++;
			temp=atoi(LINE_OPEN);
			if (temp == 1)
				shopStatus.status = true;
			else
				shopStatus.status = false;
			break;
		case 'M'://min-max
			i++;	
			shopStatus.min = atof(LINE_OPEN);
			i++;
			shopStatus.max = atof(LINE_OPEN);
			break;
		default:
			break;
		}

	}

}