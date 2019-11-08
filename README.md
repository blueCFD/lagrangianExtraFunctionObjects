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
user
git clone git://github.com/blueCFD/lagrangianExtraFunctionObjects.git
cd lagrangianExtraFunctionObjects
git checkout blueCFD-Core-2017
wmake
wclean
```

Or for getting and building from zip:

```
user
wget "https://github.com/blueCFD/lagrangianExtraFunctionObjects/archive/blueCFD-Core-2017.zip" -O lagrangianExtraFunctionObjects.zip
unzip lagrangianExtraFunctionObjects.zip
cd lagrangianExtraFunctionObjects-blueCFD-Core-2017
wmake
wclean
```

**Note**: The output that comes from the commands `wmake` and `wclean` are as follows:

```
$ wmake
wmakeLnInclude: linking include files to ./lnInclude
Making dependency list for source file writeCloudOldStyle.C
$(/home/ofuser/blueCFD/OpenFOAM-5.x/wmake/scripts/makeReinterpretExePath x86_64-w64-mingw32-g++) -std=c++11 -Dmingw_w64 -DWM_ARCH_OPTION=64 -DWM_DP -DWM_LABEL_SIZE=32 -DWIN64 -DLITTLE_ENDIAN -DWIN64 -DLITTLE_ENDIAN -Wall -Wextra -Wold-style-cast -Wnon-virtual-dtor -Wno-unused-parameter -Wno-invalid-offsetof -O2 -DNDEBUG -gdwarf  -DNoRepository -ftemplate-depth-100 -D_FILE_OFFSET_BITS=64 -D_MODE_T_ -I/home/ofuser/blueCFD/OpenFOAM-5.x/src/finiteVolume/lnInclude -I/home/ofuser/blueCFD/OpenFOAM-5.x/src/transportModels -I/home/ofuser/blueCFD/OpenFOAM-5.x/src/transportModels/incompressible/singlePhaseTransportModel -I/home/ofuser/blueCFD/OpenFOAM-5.x/src/meshTools/lnInclude -I/home/ofuser/blueCFD/OpenFOAM-5.x/src/lagrangian/basic/lnInclude -I/home/ofuser/blueCFD/OpenFOAM-5.x/src/lagrangian/intermediate/lnInclude -I/home/ofuser/blueCFD/OpenFOAM-5.x/src/lagrangian/DSMC/lnInclude -I/home/ofuser/blueCFD/OpenFOAM-5.x/src/regionModels/regionModel/lnInclude -I/home/ofuser/blueCFD/OpenFOAM-5.x/src/regionModels/surfaceFilmModels/lnInclude @Make/mingw_w64GccDPInt32Opt/includeHeaderPaths -IlnInclude -I. -I/home/ofuser/blueCFD/OpenFOAM-5.x/src/OpenFOAM/lnInclude -I/home/ofuser/blueCFD/OpenFOAM-5.x/src/OSspecific/MSwindows/lnInclude   -c writeCloudOldStyle/writeCloudOldStyle.C -o D:/DEVELO~1/Core/BLUECF~2/ofuser-of5/lagrangianExtraFunctionObjects/Make/mingw_w64GccDPInt32Opt/writeCloudOldStyle/writeCloudOldStyle.o
$(/home/ofuser/blueCFD/OpenFOAM-5.x/wmake/scripts/makeReinterpretExePath windres) Make/mingw_w64GccDPInt32Opt/version_of_build.rc Make/mingw_w64GccDPInt32Opt/version_of_build.o
$(/home/ofuser/blueCFD/OpenFOAM-5.x/wmake/scripts/makeReinterpretExePath x86_64-w64-mingw32-g++) -std=c++11 -Dmingw_w64 -DWM_ARCH_OPTION=64 -DWM_DP -DWM_LABEL_SIZE=32 -DWIN64 -DLITTLE_ENDIAN -DWIN64 -DLITTLE_ENDIAN -Wall -Wextra -Wold-style-cast -Wnon-virtual-dtor -Wno-unused-parameter -Wno-invalid-offsetof -O2 -DNDEBUG -gdwarf  -DNoRepository -ftemplate-depth-100 -D_FILE_OFFSET_BITS=64 -D_MODE_T_ -I/home/ofuser/blueCFD/OpenFOAM-5.x/src/finiteVolume/lnInclude -I/home/ofuser/blueCFD/OpenFOAM-5.x/src/transportModels -I/home/ofuser/blueCFD/OpenFOAM-5.x/src/transportModels/incompressible/singlePhaseTransportModel -I/home/ofuser/blueCFD/OpenFOAM-5.x/src/meshTools/lnInclude -I/home/ofuser/blueCFD/OpenFOAM-5.x/src/lagrangian/basic/lnInclude -I/home/ofuser/blueCFD/OpenFOAM-5.x/src/lagrangian/intermediate/lnInclude -I/home/ofuser/blueCFD/OpenFOAM-5.x/src/lagrangian/DSMC/lnInclude -I/home/ofuser/blueCFD/OpenFOAM-5.x/src/regionModels/regionModel/lnInclude -I/home/ofuser/blueCFD/OpenFOAM-5.x/src/regionModels/surfaceFilmModels/lnInclude @Make/mingw_w64GccDPInt32Opt/includeHeaderPaths -IlnInclude -I. -I/home/ofuser/blueCFD/OpenFOAM-5.x/src/OpenFOAM/lnInclude -I/home/ofuser/blueCFD/OpenFOAM-5.x/src/OSspecific/MSwindows/lnInclude   -Wl,--output-def,/home/ofuser/blueCFD/ofuser-of5/platforms/mingw_w64GccDPInt32Opt/lib/liblagrangianExtraFunctionObjects.def -Wl,--out-implib,/home/ofuser/blueCFD/ofuser-of5/platforms/mingw_w64GccDPInt32Opt/lib/liblagrangianExtraFunctionObjects.a -Wl,--enable-auto-import -shared @Make/mingw_w64GccDPInt32Opt/objectList -L/home/ofuser/blueCFD/OpenFOAM-5.x/platforms/mingw_w64GccDPInt32Opt/lib \
    -lOpenFOAM -L/home/ofuser/blueCFD/OpenFOAM-5.x/platforms/mingw_w64GccDPInt32Opt/lib/MS-MPI-7.1 -lPstream -lfiniteVolume -lincompressibleTransportModels -lmeshTools -llagrangian -llagrangianIntermediate -llagrangianTurbulence -lregionModels -lsurfaceFilmModels  -o /home/ofuser/blueCFD/ofuser-of5/platforms/mingw_w64GccDPInt32Opt/lib/liblagrangianExtraFunctionObjects.dll
/home/ofuser/blueCFD/ThirdParty-5.x/cv2pdb/cv2pdb.exe /home/ofuser/blueCFD/ofuser-of5/platforms/mingw_w64GccDPInt32Opt/lib/liblagrangianExtraFunctionObjects.dll || \
        (strip --strip-unneeded /home/ofuser/blueCFD/ofuser-of5/platforms/mingw_w64GccDPInt32Opt/lib/liblagrangianExtraFunctionObjects.dll; \
        /home/ofuser/blueCFD/OpenFOAM-5.x/wmake/scripts/infoCV2PDBworkaround)

$ wclean
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


Practical example
=================

Here is a practical example for the tutorial case `lagrangian/MPPICFoam/column`. The
following commands are used to create a copy of the tutorial case to the default `run`
folder:

```
run
cp -r $FOAM_TUTORIALS/lagrangian/MPPICFoam/column MPPICFoam_column
cd MPPICFoam_column
```

Next, it depends on your workflow:
* If you want the position files to be generated while the solver is running,
follow the steps on this section: [Example steps for doing things along with the solver](#example-steps-for-doing-things-along-with-the-solver)

* If you want the position files to be generated after the solver has already been run,
then follow the steps on this section:
[Example steps for doing things after the solver was already used and you don't want to run it again](#example-steps-for-doing-things-after-the-solver-was-already-used-and-you-dont-want-to-run-it-again)


Example steps for doing things along with the solver
----------------------------------------------------

1. Edit the file `system/controlDict` and add the block `writeCloudOldStyle1`
inside the block `functions`, as shown here:

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

2. Save the file `system/controlDict`.

3. Now you can run the solver. For this specific tutorial case, you can run the
following command, which will run `blockMesh` and `MPPICFoam` for you:

    ```
    foamRunTutorials
    ```

4. Once the solver is finished running, run these commands:

   ```
   find -name positions | while read line; do mv $line $line.coord; mv $line.orig $line; done
   find -name positions | while read line; do sed -i -e 's=^\(.*object.*\)positions.orig;=\1positions;=' $line; done
   ```

5. Finally, you can use the following command to start ParaView to open the case
with the built-in reader:

   ```
   paraFoam -builtin
   ```


Example steps for doing things after the solver was already used and you don't want to run it again
---------------------------------------------------------------------------------------------------

1. Create a new file `system/positionConvertDict` and add the following content,
as shown here:

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

2. Save the file `system/positionConvertDict`.

3. Now, assuming you already ran the solver for this tutorial, then you can run
the solver again in post-processing mode, like this:

    ```
    MPPICFoam -postProcessing -dict system/positionConvertDict
    ```

4. Once the solver is finished running, run these commands:

   ```
   find -name positions | while read line; do mv $line $line.coord; mv $line.orig $line; done
   find -name positions | while read line; do sed -i -e 's=^\(.*object.*\)positions.orig;=\1positions;=' $line; done
   ```

5. Finally, you can use the following command to start ParaView to open the case
with the built-in reader:

   ```
   paraFoam -builtin
   ```
