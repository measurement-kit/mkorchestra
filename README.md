# Measurement Kit OONI orchestra library

⚠️⚠️⚠️⚠️⚠️⚠️⚠️: This repository is unused and has been archived.

[![GitHub license](https://img.shields.io/github/license/measurement-kit/mkorchestra.svg)](https://raw.githubusercontent.com/measurement-kit/mkorchestra/master/LICENSE) [![Github Releases](https://img.shields.io/github/release/measurement-kit/mkorchestra.svg)](https://github.com/measurement-kit/mkorchestra/releases) [![Build Status](https://img.shields.io/travis/measurement-kit/mkorchestra/master.svg?label=travis)](https://travis-ci.org/measurement-kit/mkorchestra) [![codecov](https://codecov.io/gh/measurement-kit/mkorchestra/branch/master/graph/badge.svg)](https://codecov.io/gh/measurement-kit/mkorchestra) [![Build status](https://img.shields.io/appveyor/ci/bassosimone/mkorchestra/master.svg?label=appveyor)](https://ci.appveyor.com/project/bassosimone/mkorchestra/branch/master)

Experimental library to use OONI orchestra from Measurement Kit.

## Regenerating build files

Possibly edit `MKBuild.yaml`, then run:

```
go get -v github.com/measurement-kit/mkbuild
mkbuild
```

## Building

```
mkdir build
cd build
cmake -GNinja ..
cmake --build .
ctest -a -j8 --output-on-failure
```

## Testing with docker

```
./docker.sh <build-type>
```
