/*
MIT License

Copyright (C) 2023 Ryan L. Guy

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef FLUIDENGINE_GRIDUTILS_H
#define FLUIDENGINE_GRIDUTILS_H

#include "array3d.h"

namespace GridUtils {
    void extrapolateGrid(Array3d<float> *grid, Array3d<bool> *valid, int numLayers);
    void _initializeStatusGridThread(int startidx, int endidx, Array3d<bool> *valid, Array3d<char> *status);
    void _findExtrapolationCells(int startidx, int endidx, Array3d<char> *status, std::vector<GridIndex> *cells);
    void _extrapolateCellsThread(int startidx, int endidx, 
                                 std::vector<GridIndex> *cells, 
                                 Array3d<char> *status, 
                                 Array3d<float> *grid);

    void featherGrid6(Array3d<bool> *grid, int numthreads);
    void _featherGrid6Thread(Array3d<bool> *grid, Array3d<bool> *valid, int startidx, int endidx);

    void featherGrid26(Array3d<bool> *grid, int numthreads);
    void _featherGrid26Thread(Array3d<bool> *grid, Array3d<bool> *valid, int startidx, int endidx);
}

#endif