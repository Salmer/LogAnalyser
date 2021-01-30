#include "pch.h"
#include "LogAnalyserLib\LogAnalyserLib.h"

namespace LogAnalyserLib { namespace Testing { 

constexpr std::string_view testFilePath{"..\\testdata\\file1.log"};

TEST(LogReaderTests, Log_reader_can_be_created)
{
	LogAnalyserLib::LogReader readerTest;
}

TEST(LogReaderTests, Log_reader_throws_an_exception_if_file_not_found)
{
	LogAnalyserLib::LogReader readerTest;
	ASSERT_THROW(readerTest.OpenFile("unknown\\file.log"), std::runtime_error);
}

TEST(LogReaderTests, Log_reader_can_open_and_close_existing_file)
{
	LogAnalyserLib::LogReader readerTest;
	ASSERT_NO_THROW(readerTest.OpenFile(testFilePath));
}

TEST(LogReaderTests, Log_reader_can_close_existing_file_manually)
{
	LogAnalyserLib::LogReader readerTest;
	ASSERT_NO_THROW(readerTest.OpenFile(testFilePath));
	ASSERT_NO_THROW(readerTest.CloseFile());
}

TEST(LogReaderTests, Log_reader_can_read_logs)
{
	LogAnalyserLib::LogReader readerTest;
	readerTest.OpenFile(testFilePath);
	const auto acquiredData{readerTest.ReadData()};
	ASSERT_FALSE(acquiredData.empty());
}

}}