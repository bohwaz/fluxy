/*
 *  Copyright (C) 2009 Nicolas Vion <nico@picapo.net>
 *
 *   This file is part of Fluxy.
 *
 *   Fluxy is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   Fluxy is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with Fluxy; if not, write to the Free Software
 *   Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 */

#define _AUTOID_CC

#include "autoid.hh"

#include <iostream>

UserId AutoId::inc() {
	return ++id;
}

UserId AutoId::get() {
	return id;
}

void AutoId::set(UserId const value) {
	id = value;
}

void AutoId::dump(FILE *f) {
	fwrite(this, 1, sizeof(AutoId), f);
}

bool AutoId::restore(FILE *f) {
	size_t readen = fread(this, 1, sizeof(AutoId), f);
	return (readen == sizeof(AutoId));
}

AutoId::AutoId() : id(0) {
}

