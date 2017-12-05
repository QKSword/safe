#include <iostream>
#include <cstring>
void start();
void closekey(char message[]);   //加密函数
void openkey(char message[]);    //解密函数

int main()
{
	unsigned int choose;     
	char message[100];
	start();
	std::cout<<"请输入你想进行的操作：1.加密  2.解密\n";
	while(std::cin>>choose)
	{
		if(choose==1)
		{
			closekey(message);
			return 0;
		}
		else if(choose==2)
		{
			openkey(message);
			return 0;
		}
		else
		{
			std::cout<<"大哥，我们这里只能输入1和2，别和我们电脑过不去，我的主人很聪明，我这个小程序和你一样，都是很笨的，\n";
			std::cout<<"请重新输入你想要进行的操作：1.加密   2.解密\n";
		}
	}
	return 0;
}

void start()
{
	std::cout<<"                                                                                                \n";
	std::cout<<"                                              ____________                                      \n";
	std::cout<<"       __________                            /  |_________/                                     \n";
	std::cout<<"      |          |                           |  |                                               \n";
	std::cout<<"      |        __|        _________          |  |                                               \n";
	std::cout<<"      |          |       |        |          |  |_______         _______                        \n";
	std::cout<<"      |          |       |   __   |          |  |_______/       /                               \n";
	std::cout<<"      |_____     |       |  |__|  |          |  |               |_______                        \n";
	std::cout<<"      |          |       |        |          |  |               |                               \n";
	std::cout<<"      |__________|       |________|__|       |  |               |_______                        \n";
	std::cout<<"                                             |  |                                               \n";
	std::cout<<"                                             |  |                                               \n";
	std::cout<<"                                             |__|                                               \n";
	std::cout<<"                                                                                                \n";
	std::cout<<"                                                                                                \n";
}


void closekey(char message[])            //加密过程
{
	char key1[30]="QASWZXDECVFRBNGTHYJUMKIOLP";       //密匙
	char key2[30]="plijkomnhutybvfgcxerdwsqza";       //密匙
	int er=0;                                                         //错误输入截取
	int len=0;                                                        //限制长度
	char error[45];
	std::cout<<"输入你想要加密的数据(数据不能超过45位)：";
	while(len<45)
	{
		std::cin>>message;
	    len=strlen(message);
	    std::cout<<"你输入的加密数据为："<<message<<"\n";
		for(int i=0;i<len;i++)
		{
			if(message[i]>='A'&&message[i]<='Z')
			{
				message[i]=key1[message[i]-'A'];
			}
			else if(message[i]>='a'&&message[i]<='z')
			{
				message[i]=key2[message[i]-'a'];
			}
			else if (message[i]>=48&&message[i]<=57)
			{
				message[i]+=10;
			}
			else
			{
				error[er]=message[i];
				std::cout<<"你输入的"<<error[er]<<"是不能被加密的,不能保证你的密文正确\n";
			}
		}
		std::cout<<"你的密文是："<<message<<"\n\n\n";
	    std::cout<<"现在你可以继续输入你想要加密的数据:";
	}
	std::cout<<"你输入的数据大于45位，为了避免你像我主人一样是一个会黑客的大神,把我破坏了，我决定关闭程序";
	return;
}

void openkey(char message[])             //解密过程
{
	int key=0;
	char key1[30]="QASWZXDECVFRBNGTHYJUMKIOLP";           //密匙
	char key2[30]="plijkomnhutybvfgcxerdwsqza";           //密匙
	int er=0;    //错误输入的截取
	int len=0;   //限制长度  
	char error[45];       //读取错误的函数
	std::cout<<"输入你想要解密的数据：";
	while(len<45)
	{
		std::cin>>message;
	    len=strlen(message);
	    std::cout<<"你输入的解密数据为："<<message<<"\n";
		for(int i=0;i<len;i++)
		{
			if(message[i]>='A'&&message[i]<='Z')
			{
				while(key1[key]!=message[i])
				{
					++key; 
				}
				message[i]=key+'A';
				key=0;
			}
			else if(message[i]>='a'&&message[i]<='z')
			{
				while(key2[key]!=message[i])
				{
					++key;
				}
				message[i]=key+'a';
				key=0;
			}
			else if (message[i]>=58&&message[i]<=67)
			{
				message[i]-=10;
			}
			else
			{
				error[er]=message[i];
				std::cout<<"你输入的"<<error[er]<<"可能是加密时没有加密的东西，不能保证你的明文正确\n";
			}
		}
		std::cout<<"你的明文是"<<message<<"\n\n\n";
		std::cout<<"现在你可以继续你输入的解密数据:";
    }
	std::cout<<"大兄弟，你输入的数据大于45位，我还是知道你是故意耍我的";
	return ;
}
