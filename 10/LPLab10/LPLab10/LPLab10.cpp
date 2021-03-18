
#include "stdafx.h"
#include "Error.h"
#include "Parm.h"
#include "Log.h"
#include "In.h"


int wmain(int argc, wchar_t* argv[])
{
	setlocale(LC_ALL, "ru");
	
		
//▬▬▬▬▬▬▬▬ ТЕСТ ФУНКЦИИ GETERROR И GETERRORIN ▬▬▬▬▬▬▬▬ 

	/*std::cout << "---- Тест Error::geterror   ---" << std::endl << std::endl;
	try
	{throw ERROR_THROW(100);}
	catch (Error::ERROR e)
	{
		std::cout << "Ошибка " << e.id  <<": " << e.message << std::endl << std::endl;
	}

	std::cout << "---- Тест Error::geterrorin   ---" << std::endl << std::endl;
	try
	{throw ERROR_THROW_IN(111, 7, 7);}
	catch (Error::ERROR e)
	{
		std::cout << "Ошибка " << e.id << ": " << e.message 
			<< ", строка" << e.inext.line
			<< ", позиция" << e.inext.col << std::endl << std::endl;
	}
	system("pause");
	return 0;*/

//▬▬▬▬▬▬▬▬ ТЕСТ ФУНКЦИИ GETPARM ▬▬▬▬▬▬▬▬ 

	//std::cout << "---- Тест Parm::getparm  ---" << std::endl << std::endl;
	//try
	//{
	//	Parm::PARM parm = Parm::getparm(argc, argv);
	//	std::wcout << "-in: " << parm.in << std::endl << "-out: " << parm.out << std::endl << "-log: " << parm.log << std::endl << std::endl;
	//}
	//catch (Error::ERROR e)
	//{
	//	std::cout << "Ошибка " << e.id << ": " << e.message << std::endl << std::endl;
	//}
	//system("pause");
	//return 0;

//▬▬▬▬▬▬▬▬ ТЕСТ ФУНКЦИИ GETIN ▬▬▬▬▬▬▬▬ 

	//std::cout << "---- Тест In::getin  ---" << std::endl << std::endl;
	//try
	//{
	//	Parm::PARM parm = Parm::getparm(argc, argv);
	//	In::IN in = In::getin(parm.in);
	//	std::cout << in.text << std::endl;
	//	std::cout << "Всего символов: " << in.size << std::endl;
	//	std::cout << "Всего строк: " << in.lines << std::endl;
	//	std::cout << "Пропущено: " << in.ignor << std::endl;
	//}
	//catch (Error::ERROR e)
	//{
	//	std::cout << "Ошибка " << e.id << ": " << e.message << std::endl << std::endl;
	//	std::cout << "Cтрока " << e.inext.line << ", позиция" << e.inext.col << std::endl << std::endl;
	//}
	//system("pause");
	//return 0;

//▬▬▬▬▬▬▬▬ ТЕСТ ФУНКЦИЙ ИЗ ТАБЛИЦЫ 5 ▬▬▬▬▬▬▬▬ 

	std::cout << "---- Тест функций из таблицы  ---" << std::endl << std::endl;
	Log::LOG	log = Log::INITLOG;
	try
	{
		Parm::PARM parm = Parm::getparm(argc, argv);
		log = Log::getlog(parm.log);
		Log::WriteLine(log, "Тест: ", "без ошибок ", "");
		Log::WriteLog(log);
		Log::WriteParm(log, parm);
		In::IN in = In::getin(parm.in);
		Log:WriteIn(log, in);
		Log::Close(log);
	}
	catch (Error::ERROR e)
	{
		Log::WriteError(log, e);
	}
	system("pause");
	return 0;

}