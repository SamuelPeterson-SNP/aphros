// Created by Petr Karnakov on 30.07.2018
// Copyright 2018 ETH Zurich

#include "vof.ipp"
#include "embed.h"

#define X(dim) template class Vof<MeshStructured<double, dim>>;
MULTIDIMX
#undef X

#define X(dim) template class Vof<Embed<MeshStructured<double, dim>>>;
MULTIDIMX
#undef X
