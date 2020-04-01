/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | Copyright (C) 2012-2016 OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------
July 2019: Bruno Santos @ FSD blueCAPE Lda
           - created function object based on OpenFOAM's cloudInfo
November 2019: Bruno Santos @ FSD blueCAPE Lda
           - added support for MPPIC clouds
Apirl 2020: Yan Zhang @ Lund University
           - added support for spray clouds
-------------------------------------------------------------------------------
License
    This file is derivative work of OpenFOAM.

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

#include "basicKinematicMPPICCloud.H"
#include "basicKinematicMPPICParcel.H"

#include "basicSprayCloud.H"
#include "basicReactingParcel.H"

#include "IOPositionOld.H"
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

            IOPositionOld<basicKinematicCollidingCloud> ioP(cloud);
            ioP.write(cloud.nParcels() > 0);

            /*
            //If you want direct control over the output, here is an example to
            //write to screen from all processors

            forAllConstIter(basicKinematicCollidingCloud, cloud, pIter)
            {
                const basicKinematicCollidingParcel& p = pIter();

                Pout << "p:" << p.position() << endl;
            }
            */
        }
        else if (isA<basicKinematicMPPICCloud>(kcloud))
        {
            const basicKinematicMPPICCloud& cloud =
                dynamic_cast<const basicKinematicMPPICCloud&>(kcloud);

            IOPositionOld<basicKinematicMPPICCloud> ioP(cloud);
            ioP.write(cloud.nParcels() > 0);

            /*
            //If you want direct control over the output, here is an example to
            //write to screen from all processors

            forAllConstIter(basicKinematicCollidingCloud, cloud, pIter)
            {
                const basicKinematicCollidingParcel& p = pIter();

                Pout << "p:" << p.position() << endl;
            }
            */
        }
        else if (isA<basicSprayCloud>(kcloud))
        {
            const basicSprayCloud& cloud =
                dynamic_cast<const basicSprayCloud&>(kcloud);

            IOPositionOld<basicSprayCloud> ioP(cloud);
            ioP.write(cloud.nParcels() > 0);
            Info<<"cloud.nParcels()==="<<cloud.nParcels()<<endl;

            /*
            //If you want direct control over the output, here is an example to
            //write to screen from all processors

            forAllConstIter(basicSprayCloud, cloud, pIter)
            {
                const basicReactingParcel& p = pIter();

                Pout << "p:" << p.position() << endl;
            }
            */
        }      

    }

    return true;
}


// ************************************************************************* //
