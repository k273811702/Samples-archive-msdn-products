﻿using System.Linq;
using DocumentFormat.OpenXml;
using DocumentFormat.OpenXml.Packaging;
using DocumentFormat.OpenXml.Wordprocessing;

namespace ChangePrintOrientation
{
  class Program
  {
    static void Main(string[] args)
    {
      WDSetPrintOrientation(@"C:\temp\Orientation.docx", PageOrientationValues.Portrait);
    }

    // Given a document name, set the print orientation for the all the sections of the document.
    public static void WDSetPrintOrientation(
      string fileName, PageOrientationValues newOrientation)
    {
      using (var document = WordprocessingDocument.Open(fileName, true))
      {
        bool documentChanged = false;

        var docPart = document.MainDocumentPart;
        var sections = docPart.Document.Descendants<SectionProperties>();

        foreach (SectionProperties sectPr in sections)
        {
          bool pageOrientationChanged = false;

          PageSize pgSz = sectPr.Descendants<PageSize>().FirstOrDefault();
          if (pgSz != null)
          {
            // No Orient property? Create it now. Otherwise, just set its value.
            // Assume that the default orientation is Portrait.
            if (pgSz.Orient == null)
            {
              // Need to create the attribute. You do not need to 
              // create the Orient property if the property doesn't already
              // exist, and you are setting it to Portrait. That's the default value.
              if (newOrientation != PageOrientationValues.Portrait)
              {
                pageOrientationChanged = true;
                documentChanged = true;
                pgSz.Orient = new EnumValue<PageOrientationValues>(newOrientation);
              }
            }
            else
            {
              // The Orient property exists, but its value
              // is different than the new value.
              if (pgSz.Orient.Value != newOrientation)
              {
                pgSz.Orient.Value = newOrientation;
                pageOrientationChanged = true;
                documentChanged = true;
              }
            }

            if (pageOrientationChanged)
            {
              // Changing the orientation isn't enough. You must also change the page size.
              var width = pgSz.Width;
              var height = pgSz.Height;
              pgSz.Width = height;
              pgSz.Height = width;

              PageMargin pgMar = sectPr.Descendants<PageMargin>().FirstOrDefault();
              if (pgMar != null)
              {

                // Rotate margins. Printer settings control how far you 
                // rotate when switching to landscape mode. Not having those
                // settings, this code rotates 90 degrees. You could easily
                // modify this behavior, or make it a parameter for the 
                // procedure.

                var top = pgMar.Top.Value;
                var bottom = pgMar.Bottom.Value;
                var left = pgMar.Left.Value;
                var right = pgMar.Right.Value;

                pgMar.Top = new Int32Value((int)left);
                pgMar.Bottom = new Int32Value((int)right);
                pgMar.Left = new UInt32Value((uint)System.Math.Max(0, bottom));
                pgMar.Right = new UInt32Value((uint)System.Math.Max(0, top));
              }
            }
          }
        }
        if (documentChanged)
        {
          docPart.Document.Save();
        }
      }
    }

  }
}
