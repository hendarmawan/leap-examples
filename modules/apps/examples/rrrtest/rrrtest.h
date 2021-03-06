#ifndef __RRRTEST_SYSTEM__
#define __RRRTEST_SYSTEM__

#include "asim/provides/command_switches.h"
#include "asim/provides/virtual_platform.h"
#include "asim/rrr/client_stub_RRRTEST.h"

// RRRTest system

class TEST_ITERATIONS_SWITCH_CLASS : public COMMAND_SWITCH_INT_CLASS
{
  private:
    UINT32 testIter;

  public:
    ~TEST_ITERATIONS_SWITCH_CLASS() {};
    TEST_ITERATIONS_SWITCH_CLASS() :
        COMMAND_SWITCH_INT_CLASS("test-iterations"),
        testIter(10000)
    {};

    void ProcessSwitchInt(int arg) { testIter = arg; };
    void ShowSwitch(std::ostream& ostr, const string& prefix)
    {
        ostr << prefix << "[--test-iterations=<n>] RRR test iterations" << endl;
    };

    int Value(void) const { return testIter; }
};


class LONG_TESTS_SWITCH_CLASS : public COMMAND_SWITCH_INT_CLASS
{
  private:
    UINT32 longTests;

  public:
    ~LONG_TESTS_SWITCH_CLASS() {};
    LONG_TESTS_SWITCH_CLASS() :
        COMMAND_SWITCH_INT_CLASS("long-tests"),
        longTests(0)
    {};

    void ProcessSwitchInt(int arg) { longTests = arg; };
    void ShowSwitch(std::ostream& ostr, const string& prefix)
    {
        ostr << prefix << "[--long-tests=<n>]      RRR long tests if non-zero" << endl;
    };

    int Value(void) const { return longTests; }
};


typedef class CONNECTED_APPLICATION_CLASS* CONNECTED_APPLICATION;
class CONNECTED_APPLICATION_CLASS
{
  private:

    // client stub
    RRRTEST_CLIENT_STUB clientStub;

    // Arguments
    TEST_ITERATIONS_SWITCH_CLASS testIterSwitch;
    LONG_TESTS_SWITCH_CLASS longTestsSwitch;

  public:

    CONNECTED_APPLICATION_CLASS(VIRTUAL_PLATFORM vp);
    ~CONNECTED_APPLICATION_CLASS();

    // main
    void Init();
    void Main();
};

#endif
