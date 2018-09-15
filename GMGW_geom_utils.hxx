/*
 * geom_utils.hxx
 *
 *  Created on: Oct 13, 2017
 *      Author: cfog
 */

/*
    Copyright (C) The University of British Columbia, 2018.

    This file is part of UnstructuredMeshAnalyzer.

    UnstructuredMeshAnalyzer is free software: you can redistribute it
    and/or modify it under the terms of the GNU General Public License
    as published by the Free Software Foundation, either version 3 of
    the License, or (at your option) any later version.

    UnstructuredMeshAnalyzer is distributed in the hope that it will be
    useful, but WITHOUT ANY WARRANTY; without even the implied warranty
    of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with UnstructuredMeshAnalyzer.  If not, see
    <https://www.gnu.org/licenses/>.
*/

#ifndef GMGW_GEOM_UTILS_HXX_
#define GMGW_GEOM_UTILS_HXX_

#include "GMGW_FileWrapper.hxx"

#define DOT(a,b) (a[0]*b[0] + a[1]*b[1] + a[2]*b[2])
#define MAG(a) sqrt(DOT(a,a))
#define NORMALIZE(a) do {double dInvMag = 1./MAG(a); \
a[0]*=dInvMag; a[1]*=dInvMag; a[2]*=dInvMag;} while(0)

#define SUB(a,b) {a[0]-b[0], a[1]-b[1], a[2]-b[2]}
#define CROSS(a,b) {a[1]*b[2]-a[2]*b[1],\
                    a[2]*b[0]-a[0]*b[2],\
                    a[0]*b[1]-a[1]*b[0]}


void
analyzeBdryFace(const double coords[][3], const int nConn,
		const unsigned int connect[], int triFaceAngles[],
		int quadFaceAngles[], int quadDistortion[]);

void
analyzeCellQuality(const double coords[][3], const int nConn,
		   const unsigned int connect[], int triFaceAngles[],
		   int quadFaceAngles[], int quadDistortion[],
		   int dihedralsQuadQuad[], int dihedralsQuadTri[],
		   int dihedralsTriTri[]);

double
cellVolume(const double coords[][3], const int nConn,
	   const unsigned int connect[], const double sign);

double
distance(const double a[3], const double b[3]);

void
findClosestPoint(const int nConn, const unsigned int connect[], bool onBdry[],
		 const double coords[][3], double minDist[]);

void
findOffWallSpacing(const FileWrapper* wrapper, const double coords[][3],
		   const int nConn, const unsigned int connect[],
		   const int newIndex[], double volSpacing[]);

void
findOnWallSpacing(const double coords[][3], const int nConn,
		  const unsigned int connect[], const int newIndex[],
		  double skinSpacing[]);

void
outputAngleHistograms(FILE* angleFile, const int quadFaceAngles[],
		      const int triFaceAngles[], const int dihedralsQuadQuad[],
		      const int dihedralsQuadTri[],
		      const int dihedralsTriTri[]);

void
outputDistortionHistogram(FILE* distortFile, const int quadDistortion[]);

#endif /* GMGW_GEOM_UTILS_HXX_ */
