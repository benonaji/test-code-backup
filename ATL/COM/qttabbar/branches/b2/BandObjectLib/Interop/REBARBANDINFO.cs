//    This file is part of QTTabBar, a shell extension for Microsoft
//    Windows Explorer.
//    Copyright (C) 2007-2010  Quizo, Paul Accisano
//
//    QTTabBar is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    QTTabBar is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with QTTabBar.  If not, see <http://www.gnu.org/licenses/>.

namespace BandObjectLib {
    using System;
    using System.Runtime.InteropServices;

    [StructLayout(LayoutKind.Sequential)]
    public struct REBARBANDINFO {
        public int cbSize;
        public int fMask;
        public int fStyle;
        public int clrFore;
        public int clrBack;
        public IntPtr lpText;
        public int cch;
        public int iImage;
        public IntPtr hwndChild;
        public int cxMinChild;
        public int cyMinChild;
        public int cx;
        public IntPtr hbmBack;
        public int wID;
        public int cyChild;
        public int cyMaxChild;
        public int cyIntegral;
        public int cxIdeal;
        public IntPtr lParam;
        public int cxHeader;
    }
}
