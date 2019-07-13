/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 2012-2016 OpenFOAM Foundation
     \\/     M anipulation  |
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

#include "writeCloudOldStyle.H"
#include "basicKinematicCollidingCloud.H"
#include "basicKinematicCollidingParcel.H"
#include "dictionary.H"
#include "PstreamReduceOps.H"
#include "addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
namespace functionObjects
{
    defineTypeNameAndDebug(writeCloudOldStyle, 0);

    addToRunTimeSelectionTable
    (
        functionObject,
        writeCloudOldStyle,
        dictionary
    );
}
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::functionObjects::writeCloudOldStyle::writeCloudOldStyle
(
    const word& name,
    const Time& runTime,
    const dictionary& dict
)
:
    regionFunctionObject(name, runTime, dict)
{
    read(dict);
}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::functionObjects::writeCloudOldStyle::~writeCloudOldStyle()
{}


// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

bool Foam::functionObjects::writeCloudOldStyle::read(const dictionary& dict)
{
    regionFunctionObject::read(dict);

    names = wordList(dict.lookup("clouds"));

    Info<< type() << " " << name() << ": ";
    if (names.size())
    {
        Info<< "applying to clouds:" << nl;
        forAll(names, i)
        {
            Info<< "    " << names[i] << nl;
        }
        Info<< endl;
    }
    else
    {
        Info<< "no clouds to be processed" << nl << endl;
    }

    return true;
}


bool Foam::functionObjects::writeCloudOldStyle::execute()
{
    return true;
}


bool Foam::functionObjects::writeCloudOldStyle::write()
{
    forAll(names, i)
    {
        const word& cloudName = names[i];

        const kinematicCloud& kcloud =
            obr_.lookupObject<kinematicCloud>(cloudName);

        if (isA<basicKinematicCollidingCloud>(kcloud))
        {
            const basicKinematicCollidingCloud& cloud =
                dynamic_cast<const basicKinematicCollidingCloud&>(kcloud);

            forAllConstIter(basicKinematicCollidingCloud, cloud, pIter)
            {
                const basicKinematicCollidingParcel& p = pIter();

                Pout << "p:" << p.position() << endl;
            }
        }

    }

    return true;
}


// ************************************************************************* //
