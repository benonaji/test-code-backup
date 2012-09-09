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

namespace QTTabBarLib {
    using System;
    using System.Drawing;
    using System.Drawing.Imaging;
    using System.Windows.Forms;

    internal sealed class DefaultMenuRenderer : ToolStripProfessionalRenderer {
        protected override void OnRenderItemImage(ToolStripItemImageRenderEventArgs e) {
            QMenuItem item = e.Item as QMenuItem;
            if(((item != null) && item.IsCut) && ((e.ImageRectangle != Rectangle.Empty) && (e.Image != null))) {
                ColorMatrix newColorMatrix = new ColorMatrix();
                using(ImageAttributes attributes = new ImageAttributes()) {
                    newColorMatrix.Matrix33 = 0.5f;
                    attributes.SetColorMatrix(newColorMatrix);
                    Size size = e.Image.Size;
                    e.Graphics.DrawImage(e.Image, e.ImageRectangle, 0, 0, size.Width, size.Height, GraphicsUnit.Pixel, attributes);
                    return;
                }
            }
            base.OnRenderItemImage(e);
        }

        protected override void OnRenderItemText(ToolStripItemTextRenderEventArgs e) {
            e.TextFormat |= TextFormatFlags.NoPrefix;
            base.OnRenderItemText(e);
        }
    }
}
