#include <ArduinoFake.h>
#include <unity.h>

using namespace fakeit;

void test_setup(void)
{
    When(OverloadedMethod(ArduinoFake(Serial), begin, void(unsigned long))).AlwaysReturn();

    setup();

    Verify(OverloadedMethod(ArduinoFake(Serial), begin, void(unsigned long)).Using(115200)).Once();
}


void test_loop(void)
{
    When(OverloadedMethod(ArduinoFake(Serial), println, size_t(const char*))).AlwaysReturn();
    When(Method(ArduinoFake(), delay)).AlwaysReturn();

    loop();

    Verify(OverloadedMethod(ArduinoFake(Serial), println, size_t(const char*)).Using(StrEq("Hello, World!"))).Once();
    Verify(Method(ArduinoFake(), delay).Using(5000)).Once();
}

void setUp(void)
{
    ArduinoFakeReset();
}

int main(int argc, char **argv)
{
    UNITY_BEGIN();

    RUN_TEST(test_setup);
    RUN_TEST(test_loop);

    return UNITY_END();
}
