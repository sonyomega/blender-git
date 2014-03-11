/*
 * ***** BEGIN GPL LICENSE BLOCK *****
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version. 
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * The Original Code is Copyright (C) 2010 Blender Foundation.
 * All rights reserved.
 *
 * The Original Code is: all of this file.
 *
 * Contributor(s):
 *
 * ***** END GPL LICENSE BLOCK *****
 */

/** \file RE_bake.h
 *  \ingroup render
 */

#ifndef __RE_BAKE_H__
#define __RE_BAKE_H__

struct Render;
struct Mesh;

typedef struct BakePixel {
	int primitive_id;
	float u, v;
	float dudx, dudy;
	float dvdx, dvdy;
} BakePixel;

/* external_engine.c */
bool RE_engine_has_bake(struct Render *re);

bool RE_engine_bake(struct Render *re, struct Object *object, struct BakePixel pixel_array[], int num_pixels, int depth, ScenePassType pass_type, float result[]);

/* bake.c */
int RE_pass_depth(ScenePassType pass_type);
bool RE_internal_bake(struct Render *re, struct Object *object, struct BakePixel pixel_array[], int num_pixels, int depth, ScenePassType pass_type, float result[]);

void RE_populate_bake_pixels_from_object(struct Mesh *me_low, struct Mesh *me_high,
                                         struct BakePixel pixel_array_from[], struct BakePixel pixel_array_to[],
                                         const int num_pixels, const float cage_extrusion);

void RE_populate_bake_pixels(struct Mesh *me, struct BakePixel pixel_array[], const int width, const int height);

void RE_bake_margin(struct BakePixel pixel_array[], struct ImBuf *ibuf, const int margin, const int width, const int height);

void RE_normal_world_to_object(BakePixel pixel_array[], int num_pixels,  int depth, float result[], struct Object *ob, int normal_swizzle[3]);
void RE_normal_world_to_tangent(BakePixel pixel_array[], int num_pixels,  int depth, float result[], struct Mesh *me, int normal_swizzle[3]);
void RE_normal_world_to_world(BakePixel pixel_array[], int num_pixels,  int depth, float result[], int normal_swizzle[3]);

#endif