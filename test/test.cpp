#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/ui/text/TestRunner.h>
#include "../parser.h"

class MyTest : public CppUnit::TestFixture
{
   CPPUNIT_TEST_SUITE(MyTest);
   CPPUNIT_TEST(myTest1);
   CPPUNIT_TEST(myTest2);
   CPPUNIT_TEST(myTest3);
   CPPUNIT_TEST(myTest4);

   CPPUNIT_TEST_SUITE_END();
public:
   Parser p;
   void setUp() {
       // инициализация
   }
   void tearDown()    {
       // деинициализация
   }
   void myTest1()    {
	string s = "-1+5-3";
	string error;
	p.getResult(s, error);
       CPPUNIT_ASSERT(s=="1");
   }
   void myTest2()    {
	string s = "-10+(8*2.5)-(3/1,5)";
	string error;	
	p.getResult(s, error);
       	CPPUNIT_ASSERT(s=="8");
   }
   void myTest3()    {
 	string s = "1+(2*(2.5+2.5+(3-2)))-3/1.5";
	string error;	
	p.getResult(s, error);
       	CPPUNIT_ASSERT(s=="11");
    
   }

   void myTest4()    {
	string s = "1+abc";
	string error;	
	p.getResult(s, error);
       	CPPUNIT_ASSERT(error=="Некорректные ввод, строка содержит некорректный символ abc");
       
   }


};




CPPUNIT_TEST_SUITE_REGISTRATION(MyTest);

int main()
{
   CppUnit::TextUi::TestRunner runner;
   CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
   runner.addTest( registry.makeTest() );
   runner.run();
   return 0;
}
