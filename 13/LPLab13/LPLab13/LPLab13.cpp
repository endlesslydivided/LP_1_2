#include "stdafx.h"
#include "Error.h"
#include "Parm.h"
#include "Log.h"
#include "In.h"
#include "FST.h"

#define _MY_FST(x) FST::FST myFST(x, 8,\
FST::NODE(1, FST::RELATION('b', 1)), \
FST::NODE(1, FST::RELATION('m', 2)), \
FST::NODE(4, FST::RELATION('s', 2), FST::RELATION('a', 4), FST::RELATION('e', 6), FST::RELATION('r', 3)),\
FST::NODE(2, FST::RELATION('s', 2), FST::RELATION('a', 4)),\
FST::NODE(2, FST::RELATION('c', 5), FST::RELATION('p', 5)),\
FST::NODE(1, FST::RELATION('m', 2)),\
FST::NODE(1, FST::RELATION('m', 7)),\
FST::NODE())

int wmain(int argc, wchar_t* argv[])
{
	setlocale(LC_ALL, "ru");

	std::cout << "---- Тест функций из таблицы  ---" << std::endl << std::endl;
	Log::LOG	log = Log::INITLOG;
	char checkString[MAX_STRING_LENGTH];
	try
	{
	Parm::PARM parm = Parm::getparm(argc, argv);
	log = Log::getlog(parm.log);
	Log::WriteLine(log, "Тест: ", "без ошибок ", "");
	Log::WriteLog(log);
	Log::WriteParm(log, parm);
	In::IN in = In::getAllText(parm.in);
    Log::WriteIn(log, in);
	FST::CHECK_FST check_session_one = { 1,0 };
	for (int i = 0, j = 0; i < strlen((char*)in.text); j++)
	{
		checkString[i++] = in.text[j];
		check_session_one.position = i;
		/*try
		{
			checkText(in, checkString[i - 1], check_session_one.position, check_session_one.str_line);
		}
		catch(Error::ERROR e)
		{
			Log::WriteError(log, e);
		}*/
		if (checkString[i - 1] == SEPARATOR_1 )
		{
			checkString[i - 1] = END_OF_STRING;
			i = 0;
			if (checkString[0] != END_OF_STRING)
			{
				_MY_FST(checkString);
					if (FST::execute(myFST))
					{
						std::cout << "\nЦепочка " << myFST.string << " распознана.\n";
						*log.stream << "\nЦепочка " << myFST.string << " распознана.\n";
					}
					else
					{
						std::cout << "\nЦепочка " << myFST.string << " не распознана.\n";
						*log.stream << "\nЦепочка " << myFST.string << " не распознана.\n";
						std::cout << "Номер цепочки:  " << check_session_one.str_line << ". Позиция ошибки в цепочке: " << myFST.position + 1 << std::endl;
						*log.stream << "Номер цепочки:  " << check_session_one.str_line << ". Позиция ошибки в цепочке : " << myFST.position + 1 << " \n";
					}
				check_session_one.str_line++;
			}
		} 
	}
	Log::Close(log);
	}
	catch (Error::ERROR e)
	{
		Log::WriteError(log, e);
	}
	system("pause");
	return 0;

}