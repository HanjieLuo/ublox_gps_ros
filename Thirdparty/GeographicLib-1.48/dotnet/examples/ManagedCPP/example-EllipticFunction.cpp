using namespace System;
using namespace NETGeographicLib;

int main(array<System::String ^> ^/*args*/)
{
    try {
        EllipticFunction^ ell = gcnew EllipticFunction(0.1, 1.0);  // parameter m = 0.1
        // See Abramowitz and Stegun, table 17.1
        Console::WriteLine( String::Format( "{0} {1}", ell->K(), ell->E()));
        double phi = 20 * Math::Acos(-1.0) / 180.0;;
        // See Abramowitz and Stegun, table 17.6 with
        // alpha = asin(sqrt(m)) = 18.43 deg and phi = 20 deg
        Console::WriteLine( String::Format("{0} {1}", ell->E(phi),
                ell->E(Math::Sin(phi), Math::Cos(phi),
                    Math::Sqrt(1 - ell->k2 * Math::Sin(phi) * Math::Sin(phi))) ) );
        // See Carlson 1995, Sec 3.
        Console::WriteLine(String::Format("RF(1,2,0)      = {0}", EllipticFunction::RF(1,2)));
        Console::WriteLine(String::Format("RF(2,3,4)      = {0}", EllipticFunction::RF(2,3,4)));
        Console::WriteLine(String::Format("RC(0,1/4)      = {0}", EllipticFunction::RC(0,0.25)));
        Console::WriteLine(String::Format("RC(9/4,2)      = {0}", EllipticFunction::RC(2.25,2)));
        Console::WriteLine(String::Format("RC(1/4,-2)     = {0}", EllipticFunction::RC(0.25,-2)));
        Console::WriteLine(String::Format("RJ(0,1,2,3)    = {0}", EllipticFunction::RJ(0,1,2,3)));
        Console::WriteLine(String::Format("RJ(2,3,4,5)    = {0}", EllipticFunction::RJ(2,3,4,5)));
        Console::WriteLine(String::Format("RD(0,2,1)      = {0}", EllipticFunction::RD(0,2,1)));
        Console::WriteLine(String::Format("RD(2,3,4)      = {0}", EllipticFunction::RD(2,3,4)));
        Console::WriteLine(String::Format("RG(0,16,16)    = {0}", EllipticFunction::RG(16,16)));
        Console::WriteLine(String::Format("RG(2,3,4)      = {0}", EllipticFunction::RG(2,3,4)));
        Console::WriteLine(String::Format("RG(0,0.0796,4) = {0}", EllipticFunction::RG(0.0796, 4)));
    }
    catch (GeographicErr^ e) {
        Console::WriteLine( String::Format( "Caught exception: {0}", e->Message ) );
        return -1;
    }
    return 0;
}
