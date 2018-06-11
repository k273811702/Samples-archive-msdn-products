/***************************************************************************

Copyright (c) Microsoft Corporation. All rights reserved.
This code is licensed under the Visual Studio SDK license terms.
THIS CODE IS PROVIDED *AS IS* WITHOUT WARRANTY OF
ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING ANY
IMPLIED WARRANTIES OF FITNESS FOR A PARTICULAR
PURPOSE, MERCHANTABILITY, OR NON-INFRINGEMENT.

***************************************************************************/

using System;
using System.Collections.Generic;
using System.Text;
using Microsoft.Samples.VisualStudio.CodeSweep.Scanner;

namespace Microsoft.Samples.VisualStudio.CodeSweep.UnitTests
{
    class MockScanResult : IScanResult
    {
        string _filePath;
        IEnumerable<IScanHit> _hits;
        bool _scanned;

        public MockScanResult(string filePath, IEnumerable<IScanHit> hits, bool scanned)
        {
            _filePath = filePath;
            _hits = hits;
            _scanned = scanned;
        }

        #region IScanResult Members

        public string FilePath
        {
            get { return _filePath; }
        }

        public IEnumerable<IScanHit> Results
        {
            get { return _hits; }
        }

        public bool Scanned
        {
            get { return _scanned; }
        }

        public bool Passed
        {
            get
            {
                if (_scanned && _hits != null)
                {
                    foreach (IScanHit hit in _hits)
                    {
                        // If there are any hits, it didn't pass.
                        return false;
                    }
                    return true;
                }
                return false;
            }
        }

        #endregion
    }
}
