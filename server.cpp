
#include <Ice/Ice.h>
#include <HelloI.h>

using namespace std;

int main(int argc, char* argv[])
{
    int status = 0;
    Ice::CommunicatorPtr ic;

    try
    {
        ic = Ice::initialize(argc, argv);
        Ice::ObjectAdapterPtr adapter = ic->createObjectAdapterWithEndpoints("HelloAdapter", "default -p 10000");
        Ice::ObjectPtr object = new HelloI;
        adapter->add(object, ic->stringToIdentity("hello"));
        adapter->activate();
        cout << "server started, waiting for client connect..." << endl;
        ic->waitForShutdown();
    }

    catch (const Ice::Exception& e)
    {
        cerr << e << endl;
        status = 1;
    }

    catch (const char* msg)
    {
        cerr << msg << endl;
        status = 1;
    }

    if (ic)
    {
        try
        {
            ic->destroy();
        }
        catch (const Ice::Exception& e)
        {
            cerr << e << endl;
            status = 1;
        }
    }
    return status;
}
