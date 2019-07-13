lagrangianExtraFunctionObjects
==============================

**lagrangianExtraFunctionObjects** is a function object library re-adapted from
OpenFOAM 5, to write to disk in the old `positions` file format.

**Note**: This branch `blueCFD-Core-2017` refers to the code adapted to build
with blueCFD-Core 2017.

* Please see the other branches for which OpenFOAM version you can use this on.

It has been created for the [issue 111 on blueCFD-Core](https://github.com/blueCFD/Core/issues/111),
given that ParaView does not support the new `positions` format provided by
OpenFOAM 5 and newer by the [OpenFOAM Foundation](http://openfoam.org).

This is in contrast to [ESI-OpenCFD's OpenFOAM versions](http://openfoam.com),
where the new positions are actually written to the file `coordinates`, while
the old ones are still written to `positions`.

This [git repository](https://github.com/blueCFD/lagrangianExtraFunctionObjects)
was brought to you by Bruno Santos (wyldckat@github working at
[FSD blueCAPE Lda](http://www.bluecape.com.pt) - [and FS Dynamics company](http://www.fsdynamics.se)).

For problems with this library, please report it here:
https://github.com/blueCFD/lagrangianExtraFunctionObjects/issues



Disclaimer and License
======================

This offering is not approved or endorsed by OpenCFD Limited, producer and
distributor of the OpenFOAM software via www.openfoam.com, and owner of the
OPENFOAM®  and OpenCFD®  trade marks.

This is bound to the same license as OpenFOAM, namely GNU Public License v3.
Quoting from OpenFOAM's license statement:

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM. If not, see <http://www.gnu.org/licenses/>.



How to get+build lagrangianExtraFunctionObjects
===============================================

For getting and building from git:

```
git clone git://github.com/blueCFD/lagrangianExtraFunctionObjects.git
cd lagrangianExtraFunctionObjects
git checkout blueCFD-Core-2017
wmake
wclean
```

Or for getting and building from zip:

```
wget "https://github.com/blueCFD/lagrangianExtraFunctionObjects/archive/blueCFD-Core-2017.zip" -O lagrangianExtraFunctionObjects.zip
unzip lagrangianExtraFunctionObjects.zip
cd lagrangianExtraFunctionObjects-blueCFD-Core-2017
wmake
wclean
```


How to use it
=============

For the function object, simply add the following block to your
`system/controlDict`, inside the block `functions`, e.g.:

```
functions
{
    writeCloudOldStyle1
    {
        type        writeCloudOldStyle;
        libs        ("liblagrangianExtraFunctionObjects.so");

        writeControl writeTime;

        clouds
        (
            kinematicCloud
        );
    }
}
```

Correct the name `kinematicCloud` to the actual name of the cloud you want to
track, which should be implied in the file name for the respective cloud, e.g.
`constant/kinematicCloudProperties` refers to `kinematicCloud`.

This function object will create the position files `positions.orig` inside each
time step cloud folder, e.g. in the folder `5e-05/lagrangian/kinematicCloud`.

Therefore, before you run `paraFoam -builtin`, you must run these commands:

```
find -name positions | while read line; do mv $line $line.coord; mv $line.orig $line; done
find -name positions | while read line; do sed -i -e 's=^\(.*object.*\)positions.orig;=\1positions;=' $line; done
```

They will rename all `positions` files to `positions.coord`, along with renaming
and correcting the files `positions.orig` to `positions`.

But keep in mind that before you can continue the simulation, you must run the
following command:

```
find -name positions | while read line; do mv $line $line.orig; mv $line.coord $line; done
```
