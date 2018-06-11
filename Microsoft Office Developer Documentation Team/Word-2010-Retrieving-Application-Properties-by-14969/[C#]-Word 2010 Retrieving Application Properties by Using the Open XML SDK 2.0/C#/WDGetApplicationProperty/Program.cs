﻿using System;
using DocumentFormat.OpenXml.Packaging;

namespace WDGetApplicationProperty
{
  class Program
  {

    private const string FILENAME = @"C:\Samples\DocumentProperties.docx";

    static void Main(string[] args)
    {
      using (WordprocessingDocument document = WordprocessingDocument.Open(FILENAME, false))
      {
        var props = document.ExtendedFilePropertiesPart.Properties;

        if (props.Company != null)
          Console.WriteLine("Company = " + props.Company.Text);

        if (props.Lines != null)
          Console.WriteLine("Lines = " + props.Lines.Text);

        if (props.Manager != null)
          Console.WriteLine("Manager = " + props.Manager.Text);
      }
    }
  }
}