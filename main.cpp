/**
*  Copyright (c) 2012, CSUMB
*  All rights reserved.
*
*  Redistribution and use in source and binary forms, with or
*  without modification, are permitted provided that the following conditions are met:
*
*  Redistributions of source code must retain the above copyright notice,
*  this list of conditions and the following disclaimer. Redistributions
*  in binary form must reproduce the above copyright notice, this list of
*  conditions and the following disclaimer in the documentation and/or other
*  materials provided with the distribution.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
*  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
*  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
*  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
*  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
*  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF
*  USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
*  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
*  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
/**
*  Author: Philip Cooksey
*/

#include <iostream>
#include <list>
#include <vector>
#include "Puzzle.hh"
#include "PartialSolver.hh"
using namespace std;

int main()
{
    Puzzle puzzle;
    bool success = puzzle.loadFile();
    if(success)
    {
        list<vector<SkyScraper> > possible = puzzle.generatorRows(0, true);
        list<vector<SkyScraper>  >::iterator begin = possible.begin(), end = possible.end();
        for(; begin!=end; begin++)
        {
            for(int i=0; i<begin->size(); i++)
            {
                cout<<(*begin)[i]<<" ";
            }
            cout<<endl;
        }

        /*
        puzzle.checkOutside();
        try
        {
            puzzle.solve();
            if(puzzle.complete())
            {
                cout<<"Completely Solved"<<endl;
                if(!puzzle.correct())
                {
                    cout<<"Not Correct!"<<endl;
                }
                puzzle.print(true);
            }
            else
            {
                cout<<"Partially Solved"<<endl;
                puzzle.print(true);
                //cin.sync(); cin.get();
                PartialSolver solver(puzzle);
                solver.solve();
                solver.print();
                solver.boundaryFinder();
            }
        } catch (bool &err) {
            cout<<"Failed to solve!";
        }
        */
    }
    else
    {
        cout<<"File not found!"<<endl;
    }
    return 0;
}
