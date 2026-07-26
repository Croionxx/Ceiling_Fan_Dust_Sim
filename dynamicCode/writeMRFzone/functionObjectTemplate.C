/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | www.openfoam.com
     \\/     M anipulation  |
-------------------------------------------------------------------------------
    Copyright (C) 2019-2021 OpenCFD Ltd.
    Copyright (C) YEAR AUTHOR, AFFILIATION
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

\*---------------------------------------------------------------------------*/

#include "functionObjectTemplate.H"
#define namespaceFoam  // Suppress <using namespace Foam;>
#include "fvCFD.H"
#include "unitConversion.H"
#include "addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

defineTypeNameAndDebug(writeMRFzoneFunctionObject, 0);

addRemovableToRunTimeSelectionTable
(
    functionObject,
    writeMRFzoneFunctionObject,
    dictionary
);


// * * * * * * * * * * * * * * * Global Functions  * * * * * * * * * * * * * //

// dynamicCode:
// SHA1 = 6377c08eba248a5b9134d13eaa34fa11c2e9903e
//
// unique function name that can be checked if the correct library version
// has been loaded
extern "C" void writeMRFzone_6377c08eba248a5b9134d13eaa34fa11c2e9903e(bool load)
{
    if (load)
    {
        // Code that can be explicitly executed after loading
    }
    else
    {
        // Code that can be explicitly executed before unloading
    }
}


// * * * * * * * * * * * * * * * Local Functions * * * * * * * * * * * * * * //

//{{{ begin localCode

//}}} end localCode

} // End namespace Foam


// * * * * * * * * * * * * * Private Member Functions  * * * * * * * * * * * //

const Foam::fvMesh&
Foam::writeMRFzoneFunctionObject::mesh() const
{
    return refCast<const fvMesh>(obr_);
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::
writeMRFzoneFunctionObject::
writeMRFzoneFunctionObject
(
    const word& name,
    const Time& runTime,
    const dictionary& dict
)
:
    functionObjects::regionFunctionObject(name, runTime, dict)
{
    read(dict);
}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::
writeMRFzoneFunctionObject::
~writeMRFzoneFunctionObject()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

bool
Foam::
writeMRFzoneFunctionObject::read(const dictionary& dict)
{
    if (false)
    {
        printMessage("read writeMRFzone");
    }

//{{{ begin code
    
//}}} end code

    return true;
}


bool
Foam::
writeMRFzoneFunctionObject::execute()
{
    if (false)
    {
        printMessage("execute writeMRFzone");
    }

//{{{ begin code
    #line 15 "functions/MRFzoneField"
auto& mesh = refCast<const fvMesh>(obr_);

    volScalarField MRFzone
    (
        IOobject
        (
            "MRFzone",
            mesh.time().timeName(),
            mesh,
            IOobject::NO_READ,
            IOobject::AUTO_WRITE
        ),
        mesh,
        dimensionedScalar("zero", dimless, 0)
    );

    const label zoneID = mesh.cellZones().findZoneID("fanZone");
    if (zoneID != -1)
    {
        const cellZone& zone = mesh.cellZones()[zoneID];
        forAll(zone, i)
        {
            MRFzone[zone[i]] = 1.0;
        }
    }

    MRFzone.write();
    Info << "Wrote MRFzone field" << endl;
//}}} end code

    return true;
}


bool
Foam::
writeMRFzoneFunctionObject::write()
{
    if (false)
    {
        printMessage("write writeMRFzone");
    }

//{{{ begin code
    
//}}} end code

    return true;
}


bool
Foam::
writeMRFzoneFunctionObject::end()
{
    if (false)
    {
        printMessage("end writeMRFzone");
    }

//{{{ begin code
    
//}}} end code

    return true;
}


// ************************************************************************* //

