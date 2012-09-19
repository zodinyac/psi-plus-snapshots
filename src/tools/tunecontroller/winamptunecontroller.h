/*
 * winamptunecontroller.h
 * Copyright (C) 2006  Remko Troncon,
 * 2012  Vitaly Tonkacheyev
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
 * along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */

#ifndef WINAMPTUNECONTROLLER_H
#define WINAMPTUNECONTROLLER_H

#include "pollingtunecontroller.h"

#include <windows.h>
#include <QPair>

class WinAmpController : public PollingTuneController
{
	Q_OBJECT
public:
	WinAmpController();
	virtual Tune currentTune() const;

protected slots:
	void check();

private:
	bool getData(const HANDLE& hProcess, const HWND& hWnd, const wchar_t *filename, const wchar_t *metadata, wchar_t *wresult);
	Tune getTune(const HWND &hWnd);
	QPair<bool, QString> getTrackTitle(const HWND &waWnd) const;

private:
	Tune prevTune_;
	int antiscrollCounter_;
};

#endif
