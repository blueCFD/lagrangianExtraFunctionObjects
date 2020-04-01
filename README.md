# lagrangianExtraFunctionObjects

**lagrangianExtraFunctionObjects** is a function object library re-adapted from
OpenFOAM 5, to write to disk in the old `positions` file format.

Please see the other [branches](https://github.com/blueCFD/lagrangianExtraFunctionObjects/branches)
for which OpenFOAM version you can use this on.

It has been created for the [issue 111 on blueCFD-Core](https://github.com/blueCFD/Core/issues/111),
given that ParaView does not support the new `positions` format provided by
OpenFOAM 5 and newer by the [OpenFOAM Foundation](http://openfoam.org).

This is in contrast to [ESI-OpenCFD's OpenFOAM versions](http://openfoam.com),
where the new positions are actually written to the file `coordinates`, while
the old ones are still written to `positions`.

This [git repository](https://github.com/blueCFD/lagrangianExtraFunctionObjects)
was brought to you by Bruno Santos (wyldckat@github working at
[FSD blueCAPE Lda](http://www.bluecape.com.pt) - [and FS Dynamics company](http://www.fsdynamics.se)).

Contributions are accepted and respective contributors are also added to
the README files associated to each branch.

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

