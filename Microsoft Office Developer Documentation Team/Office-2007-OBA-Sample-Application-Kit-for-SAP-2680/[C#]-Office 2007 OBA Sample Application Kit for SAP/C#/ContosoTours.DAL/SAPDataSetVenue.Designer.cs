﻿//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//     Runtime Version:2.0.50727.1378
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

#pragma warning disable 1591

namespace Microsoft.SAPSK.ContosoTours.DAL {
    
    
    /// <summary>
    ///Represents a strongly typed in-memory cache of data.
    ///</summary>
    [global::System.CodeDom.Compiler.GeneratedCodeAttribute("System.Data.Design.TypedDataSetGenerator", "2.0.0.0")]
    [global::System.Serializable()]
    [global::System.ComponentModel.DesignerCategoryAttribute("code")]
    [global::System.ComponentModel.ToolboxItem(true)]
    [global::System.Xml.Serialization.XmlSchemaProviderAttribute("GetTypedDataSetSchema")]
    [global::System.Xml.Serialization.XmlRootAttribute("SAPDataSetVenue")]
    [global::System.ComponentModel.Design.HelpKeywordAttribute("vs.data.DataSet")]
    public partial class SAPDataSetVenue : global::System.Data.DataSet {
        
        private VenueDataTable tableVenue;
        
        private global::System.Data.SchemaSerializationMode _schemaSerializationMode = global::System.Data.SchemaSerializationMode.IncludeSchema;
        
        [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
        public SAPDataSetVenue() {
            this.BeginInit();
            this.InitClass();
            global::System.ComponentModel.CollectionChangeEventHandler schemaChangedHandler = new global::System.ComponentModel.CollectionChangeEventHandler(this.SchemaChanged);
            base.Tables.CollectionChanged += schemaChangedHandler;
            base.Relations.CollectionChanged += schemaChangedHandler;
            this.EndInit();
        }
        
        [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
        protected SAPDataSetVenue(global::System.Runtime.Serialization.SerializationInfo info, global::System.Runtime.Serialization.StreamingContext context) : 
                base(info, context, false) {
            if ((this.IsBinarySerialized(info, context) == true)) {
                this.InitVars(false);
                global::System.ComponentModel.CollectionChangeEventHandler schemaChangedHandler1 = new global::System.ComponentModel.CollectionChangeEventHandler(this.SchemaChanged);
                this.Tables.CollectionChanged += schemaChangedHandler1;
                this.Relations.CollectionChanged += schemaChangedHandler1;
                return;
            }
            string strSchema = ((string)(info.GetValue("XmlSchema", typeof(string))));
            if ((this.DetermineSchemaSerializationMode(info, context) == global::System.Data.SchemaSerializationMode.IncludeSchema)) {
                global::System.Data.DataSet ds = new global::System.Data.DataSet();
                ds.ReadXmlSchema(new global::System.Xml.XmlTextReader(new global::System.IO.StringReader(strSchema)));
                if ((ds.Tables["Venue"] != null)) {
                    base.Tables.Add(new VenueDataTable(ds.Tables["Venue"]));
                }
                this.DataSetName = ds.DataSetName;
                this.Prefix = ds.Prefix;
                this.Namespace = ds.Namespace;
                this.Locale = ds.Locale;
                this.CaseSensitive = ds.CaseSensitive;
                this.EnforceConstraints = ds.EnforceConstraints;
                this.Merge(ds, false, global::System.Data.MissingSchemaAction.Add);
                this.InitVars();
            }
            else {
                this.ReadXmlSchema(new global::System.Xml.XmlTextReader(new global::System.IO.StringReader(strSchema)));
            }
            this.GetSerializationData(info, context);
            global::System.ComponentModel.CollectionChangeEventHandler schemaChangedHandler = new global::System.ComponentModel.CollectionChangeEventHandler(this.SchemaChanged);
            base.Tables.CollectionChanged += schemaChangedHandler;
            this.Relations.CollectionChanged += schemaChangedHandler;
        }
        
        [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
        [global::System.ComponentModel.Browsable(false)]
        [global::System.ComponentModel.DesignerSerializationVisibility(global::System.ComponentModel.DesignerSerializationVisibility.Content)]
        public VenueDataTable Venue {
            get {
                return this.tableVenue;
            }
        }
        
        [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
        [global::System.ComponentModel.BrowsableAttribute(true)]
        [global::System.ComponentModel.DesignerSerializationVisibilityAttribute(global::System.ComponentModel.DesignerSerializationVisibility.Visible)]
        public override global::System.Data.SchemaSerializationMode SchemaSerializationMode {
            get {
                return this._schemaSerializationMode;
            }
            set {
                this._schemaSerializationMode = value;
            }
        }
        
        [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
        [global::System.ComponentModel.DesignerSerializationVisibilityAttribute(global::System.ComponentModel.DesignerSerializationVisibility.Hidden)]
        public new global::System.Data.DataTableCollection Tables {
            get {
                return base.Tables;
            }
        }
        
        [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
        [global::System.ComponentModel.DesignerSerializationVisibilityAttribute(global::System.ComponentModel.DesignerSerializationVisibility.Hidden)]
        public new global::System.Data.DataRelationCollection Relations {
            get {
                return base.Relations;
            }
        }
        
        [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
        protected override void InitializeDerivedDataSet() {
            this.BeginInit();
            this.InitClass();
            this.EndInit();
        }
        
        [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
        public override global::System.Data.DataSet Clone() {
            SAPDataSetVenue cln = ((SAPDataSetVenue)(base.Clone()));
            cln.InitVars();
            cln.SchemaSerializationMode = this.SchemaSerializationMode;
            return cln;
        }
        
        [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
        protected override bool ShouldSerializeTables() {
            return false;
        }
        
        [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
        protected override bool ShouldSerializeRelations() {
            return false;
        }
        
        [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
        protected override void ReadXmlSerializable(global::System.Xml.XmlReader reader) {
            if ((this.DetermineSchemaSerializationMode(reader) == global::System.Data.SchemaSerializationMode.IncludeSchema)) {
                this.Reset();
                global::System.Data.DataSet ds = new global::System.Data.DataSet();
                ds.ReadXml(reader);
                if ((ds.Tables["Venue"] != null)) {
                    base.Tables.Add(new VenueDataTable(ds.Tables["Venue"]));
                }
                this.DataSetName = ds.DataSetName;
                this.Prefix = ds.Prefix;
                this.Namespace = ds.Namespace;
                this.Locale = ds.Locale;
                this.CaseSensitive = ds.CaseSensitive;
                this.EnforceConstraints = ds.EnforceConstraints;
                this.Merge(ds, false, global::System.Data.MissingSchemaAction.Add);
                this.InitVars();
            }
            else {
                this.ReadXml(reader);
                this.InitVars();
            }
        }
        
        [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
        protected override global::System.Xml.Schema.XmlSchema GetSchemaSerializable() {
            global::System.IO.MemoryStream stream = new global::System.IO.MemoryStream();
            this.WriteXmlSchema(new global::System.Xml.XmlTextWriter(stream, null));
            stream.Position = 0;
            return global::System.Xml.Schema.XmlSchema.Read(new global::System.Xml.XmlTextReader(stream), null);
        }
        
        [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
        internal void InitVars() {
            this.InitVars(true);
        }
        
        [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
        internal void InitVars(bool initTable) {
            this.tableVenue = ((VenueDataTable)(base.Tables["Venue"]));
            if ((initTable == true)) {
                if ((this.tableVenue != null)) {
                    this.tableVenue.InitVars();
                }
            }
        }
        
        [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
        private void InitClass() {
            this.DataSetName = "SAPDataSetVenue";
            this.Prefix = "";
            this.EnforceConstraints = true;
            this.SchemaSerializationMode = global::System.Data.SchemaSerializationMode.IncludeSchema;
            this.tableVenue = new VenueDataTable();
            base.Tables.Add(this.tableVenue);
        }
        
        [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
        private bool ShouldSerializeVenue() {
            return false;
        }
        
        [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
        private void SchemaChanged(object sender, global::System.ComponentModel.CollectionChangeEventArgs e) {
            if ((e.Action == global::System.ComponentModel.CollectionChangeAction.Remove)) {
                this.InitVars();
            }
        }
        
        [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
        public static global::System.Xml.Schema.XmlSchemaComplexType GetTypedDataSetSchema(global::System.Xml.Schema.XmlSchemaSet xs) {
            SAPDataSetVenue ds = new SAPDataSetVenue();
            global::System.Xml.Schema.XmlSchemaComplexType type = new global::System.Xml.Schema.XmlSchemaComplexType();
            global::System.Xml.Schema.XmlSchemaSequence sequence = new global::System.Xml.Schema.XmlSchemaSequence();
            xs.Add(ds.GetSchemaSerializable());
            global::System.Xml.Schema.XmlSchemaAny any = new global::System.Xml.Schema.XmlSchemaAny();
            any.Namespace = ds.Namespace;
            sequence.Items.Add(any);
            type.Particle = sequence;
            return type;
        }
        
        public delegate void VenueRowChangeEventHandler(object sender, VenueRowChangeEvent e);
        
        /// <summary>
        ///Represents the strongly named DataTable class.
        ///</summary>
        [global::System.CodeDom.Compiler.GeneratedCodeAttribute("System.Data.Design.TypedDataSetGenerator", "2.0.0.0")]
        [global::System.Serializable()]
        [global::System.Xml.Serialization.XmlSchemaProviderAttribute("GetTypedTableSchema")]
        public partial class VenueDataTable : global::System.Data.DataTable, global::System.Collections.IEnumerable {
            
            private global::System.Data.DataColumn columnVenueID;
            
            private global::System.Data.DataColumn columnVenueName;
            
            private global::System.Data.DataColumn columnVenueDescription;
            
            private global::System.Data.DataColumn columnVenueStreet;
            
            private global::System.Data.DataColumn columnVenueCity;
            
            private global::System.Data.DataColumn columnVenueState;
            
            private global::System.Data.DataColumn columnVenuePostalCode;
            
            private global::System.Data.DataColumn columnVenueGeographicMap;
            
            private global::System.Data.DataColumn columnVenueFacilityMap;
            
            private global::System.Data.DataColumn columnVenueImage;
            
            [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
            public VenueDataTable() {
                this.TableName = "Venue";
                this.BeginInit();
                this.InitClass();
                this.EndInit();
            }
            
            [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
            internal VenueDataTable(global::System.Data.DataTable table) {
                this.TableName = table.TableName;
                if ((table.CaseSensitive != table.DataSet.CaseSensitive)) {
                    this.CaseSensitive = table.CaseSensitive;
                }
                if ((table.Locale.ToString() != table.DataSet.Locale.ToString())) {
                    this.Locale = table.Locale;
                }
                if ((table.Namespace != table.DataSet.Namespace)) {
                    this.Namespace = table.Namespace;
                }
                this.Prefix = table.Prefix;
                this.MinimumCapacity = table.MinimumCapacity;
            }
            
            [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
            protected VenueDataTable(global::System.Runtime.Serialization.SerializationInfo info, global::System.Runtime.Serialization.StreamingContext context) : 
                    base(info, context) {
                this.InitVars();
            }
            
            [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
            public global::System.Data.DataColumn VenueIDColumn {
                get {
                    return this.columnVenueID;
                }
            }
            
            [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
            public global::System.Data.DataColumn VenueNameColumn {
                get {
                    return this.columnVenueName;
                }
            }
            
            [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
            public global::System.Data.DataColumn VenueDescriptionColumn {
                get {
                    return this.columnVenueDescription;
                }
            }
            
            [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
            public global::System.Data.DataColumn VenueStreetColumn {
                get {
                    return this.columnVenueStreet;
                }
            }
            
            [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
            public global::System.Data.DataColumn VenueCityColumn {
                get {
                    return this.columnVenueCity;
                }
            }
            
            [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
            public global::System.Data.DataColumn VenueStateColumn {
                get {
                    return this.columnVenueState;
                }
            }
            
            [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
            public global::System.Data.DataColumn VenuePostalCodeColumn {
                get {
                    return this.columnVenuePostalCode;
                }
            }
            
            [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
            public global::System.Data.DataColumn VenueGeographicMapColumn {
                get {
                    return this.columnVenueGeographicMap;
                }
            }
            
            [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
            public global::System.Data.DataColumn VenueFacilityMapColumn {
                get {
                    return this.columnVenueFacilityMap;
                }
            }
            
            [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
            public global::System.Data.DataColumn VenueImageColumn {
                get {
                    return this.columnVenueImage;
                }
            }
            
            [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
            [global::System.ComponentModel.Browsable(false)]
            public int Count {
                get {
                    return this.Rows.Count;
                }
            }
            
            [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
            public VenueRow this[int index] {
                get {
                    return ((VenueRow)(this.Rows[index]));
                }
            }
            
            public event VenueRowChangeEventHandler VenueRowChanging;
            
            public event VenueRowChangeEventHandler VenueRowChanged;
            
            public event VenueRowChangeEventHandler VenueRowDeleting;
            
            public event VenueRowChangeEventHandler VenueRowDeleted;
            
            [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
            public void AddVenueRow(VenueRow row) {
                this.Rows.Add(row);
            }
            
            [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
            public VenueRow AddVenueRow(string VenueName, string VenueDescription, string VenueStreet, string VenueCity, string VenueState, string VenuePostalCode, byte[] VenueGeographicMap, byte[] VenueFacilityMap, byte[] VenueImage) {
                VenueRow rowVenueRow = ((VenueRow)(this.NewRow()));
                object[] columnValuesArray = new object[] {
                        null,
                        VenueName,
                        VenueDescription,
                        VenueStreet,
                        VenueCity,
                        VenueState,
                        VenuePostalCode,
                        VenueGeographicMap,
                        VenueFacilityMap,
                        VenueImage};
                rowVenueRow.ItemArray = columnValuesArray;
                this.Rows.Add(rowVenueRow);
                return rowVenueRow;
            }
            
            [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
            public VenueRow FindByVenueID(int VenueID) {
                return ((VenueRow)(this.Rows.Find(new object[] {
                            VenueID})));
            }
            
            [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
            public virtual global::System.Collections.IEnumerator GetEnumerator() {
                return this.Rows.GetEnumerator();
            }
            
            [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
            public override global::System.Data.DataTable Clone() {
                VenueDataTable cln = ((VenueDataTable)(base.Clone()));
                cln.InitVars();
                return cln;
            }
            
            [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
            protected override global::System.Data.DataTable CreateInstance() {
                return new VenueDataTable();
            }
            
            [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
            internal void InitVars() {
                this.columnVenueID = base.Columns["VenueID"];
                this.columnVenueName = base.Columns["VenueName"];
                this.columnVenueDescription = base.Columns["VenueDescription"];
                this.columnVenueStreet = base.Columns["VenueStreet"];
                this.columnVenueCity = base.Columns["VenueCity"];
                this.columnVenueState = base.Columns["VenueState"];
                this.columnVenuePostalCode = base.Columns["VenuePostalCode"];
                this.columnVenueGeographicMap = base.Columns["VenueGeographicMap"];
                this.columnVenueFacilityMap = base.Columns["VenueFacilityMap"];
                this.columnVenueImage = base.Columns["VenueImage"];
            }
            
            [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
            private void InitClass() {
                this.columnVenueID = new global::System.Data.DataColumn("VenueID", typeof(int), null, global::System.Data.MappingType.Element);
                base.Columns.Add(this.columnVenueID);
                this.columnVenueName = new global::System.Data.DataColumn("VenueName", typeof(string), null, global::System.Data.MappingType.Element);
                base.Columns.Add(this.columnVenueName);
                this.columnVenueDescription = new global::System.Data.DataColumn("VenueDescription", typeof(string), null, global::System.Data.MappingType.Element);
                base.Columns.Add(this.columnVenueDescription);
                this.columnVenueStreet = new global::System.Data.DataColumn("VenueStreet", typeof(string), null, global::System.Data.MappingType.Element);
                base.Columns.Add(this.columnVenueStreet);
                this.columnVenueCity = new global::System.Data.DataColumn("VenueCity", typeof(string), null, global::System.Data.MappingType.Element);
                base.Columns.Add(this.columnVenueCity);
                this.columnVenueState = new global::System.Data.DataColumn("VenueState", typeof(string), null, global::System.Data.MappingType.Element);
                base.Columns.Add(this.columnVenueState);
                this.columnVenuePostalCode = new global::System.Data.DataColumn("VenuePostalCode", typeof(string), null, global::System.Data.MappingType.Element);
                base.Columns.Add(this.columnVenuePostalCode);
                this.columnVenueGeographicMap = new global::System.Data.DataColumn("VenueGeographicMap", typeof(byte[]), null, global::System.Data.MappingType.Element);
                base.Columns.Add(this.columnVenueGeographicMap);
                this.columnVenueFacilityMap = new global::System.Data.DataColumn("VenueFacilityMap", typeof(byte[]), null, global::System.Data.MappingType.Element);
                base.Columns.Add(this.columnVenueFacilityMap);
                this.columnVenueImage = new global::System.Data.DataColumn("VenueImage", typeof(byte[]), null, global::System.Data.MappingType.Element);
                base.Columns.Add(this.columnVenueImage);
                this.Constraints.Add(new global::System.Data.UniqueConstraint("Constraint1", new global::System.Data.DataColumn[] {
                                this.columnVenueID}, true));
                this.columnVenueID.AutoIncrement = true;
                this.columnVenueID.AllowDBNull = false;
                this.columnVenueID.ReadOnly = true;
                this.columnVenueID.Unique = true;
                this.columnVenueName.AllowDBNull = false;
                this.columnVenueName.MaxLength = 255;
                this.columnVenueDescription.AllowDBNull = false;
                this.columnVenueDescription.MaxLength = 4000;
                this.columnVenueStreet.AllowDBNull = false;
                this.columnVenueStreet.MaxLength = 255;
                this.columnVenueCity.AllowDBNull = false;
                this.columnVenueCity.MaxLength = 255;
                this.columnVenueState.AllowDBNull = false;
                this.columnVenueState.MaxLength = 255;
                this.columnVenuePostalCode.AllowDBNull = false;
                this.columnVenuePostalCode.MaxLength = 25;
                this.columnVenueGeographicMap.AllowDBNull = false;
                this.columnVenueFacilityMap.AllowDBNull = false;
                this.columnVenueImage.AllowDBNull = false;
            }
            
            [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
            public VenueRow NewVenueRow() {
                return ((VenueRow)(this.NewRow()));
            }
            
            [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
            protected override global::System.Data.DataRow NewRowFromBuilder(global::System.Data.DataRowBuilder builder) {
                return new VenueRow(builder);
            }
            
            [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
            protected override global::System.Type GetRowType() {
                return typeof(VenueRow);
            }
            
            [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
            protected override void OnRowChanged(global::System.Data.DataRowChangeEventArgs e) {
                base.OnRowChanged(e);
                if ((this.VenueRowChanged != null)) {
                    this.VenueRowChanged(this, new VenueRowChangeEvent(((VenueRow)(e.Row)), e.Action));
                }
            }
            
            [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
            protected override void OnRowChanging(global::System.Data.DataRowChangeEventArgs e) {
                base.OnRowChanging(e);
                if ((this.VenueRowChanging != null)) {
                    this.VenueRowChanging(this, new VenueRowChangeEvent(((VenueRow)(e.Row)), e.Action));
                }
            }
            
            [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
            protected override void OnRowDeleted(global::System.Data.DataRowChangeEventArgs e) {
                base.OnRowDeleted(e);
                if ((this.VenueRowDeleted != null)) {
                    this.VenueRowDeleted(this, new VenueRowChangeEvent(((VenueRow)(e.Row)), e.Action));
                }
            }
            
            [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
            protected override void OnRowDeleting(global::System.Data.DataRowChangeEventArgs e) {
                base.OnRowDeleting(e);
                if ((this.VenueRowDeleting != null)) {
                    this.VenueRowDeleting(this, new VenueRowChangeEvent(((VenueRow)(e.Row)), e.Action));
                }
            }
            
            [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
            public void RemoveVenueRow(VenueRow row) {
                this.Rows.Remove(row);
            }
            
            [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
            public static global::System.Xml.Schema.XmlSchemaComplexType GetTypedTableSchema(global::System.Xml.Schema.XmlSchemaSet xs) {
                global::System.Xml.Schema.XmlSchemaComplexType type = new global::System.Xml.Schema.XmlSchemaComplexType();
                global::System.Xml.Schema.XmlSchemaSequence sequence = new global::System.Xml.Schema.XmlSchemaSequence();
                SAPDataSetVenue ds = new SAPDataSetVenue();
                xs.Add(ds.GetSchemaSerializable());
                global::System.Xml.Schema.XmlSchemaAny any1 = new global::System.Xml.Schema.XmlSchemaAny();
                any1.Namespace = "http://www.w3.org/2001/XMLSchema";
                any1.MinOccurs = new decimal(0);
                any1.MaxOccurs = decimal.MaxValue;
                any1.ProcessContents = global::System.Xml.Schema.XmlSchemaContentProcessing.Lax;
                sequence.Items.Add(any1);
                global::System.Xml.Schema.XmlSchemaAny any2 = new global::System.Xml.Schema.XmlSchemaAny();
                any2.Namespace = "urn:schemas-microsoft-com:xml-diffgram-v1";
                any2.MinOccurs = new decimal(1);
                any2.ProcessContents = global::System.Xml.Schema.XmlSchemaContentProcessing.Lax;
                sequence.Items.Add(any2);
                global::System.Xml.Schema.XmlSchemaAttribute attribute1 = new global::System.Xml.Schema.XmlSchemaAttribute();
                attribute1.Name = "namespace";
                attribute1.FixedValue = ds.Namespace;
                type.Attributes.Add(attribute1);
                global::System.Xml.Schema.XmlSchemaAttribute attribute2 = new global::System.Xml.Schema.XmlSchemaAttribute();
                attribute2.Name = "tableTypeName";
                attribute2.FixedValue = "VenueDataTable";
                type.Attributes.Add(attribute2);
                type.Particle = sequence;
                return type;
            }
        }
        
        /// <summary>
        ///Represents strongly named DataRow class.
        ///</summary>
        [global::System.CodeDom.Compiler.GeneratedCodeAttribute("System.Data.Design.TypedDataSetGenerator", "2.0.0.0")]
        public partial class VenueRow : global::System.Data.DataRow {
            
            private VenueDataTable tableVenue;
            
            [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
            internal VenueRow(global::System.Data.DataRowBuilder rb) : 
                    base(rb) {
                this.tableVenue = ((VenueDataTable)(this.Table));
            }
            
            [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
            public int VenueID {
                get {
                    return ((int)(this[this.tableVenue.VenueIDColumn]));
                }
                set {
                    this[this.tableVenue.VenueIDColumn] = value;
                }
            }
            
            [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
            public string VenueName {
                get {
                    return ((string)(this[this.tableVenue.VenueNameColumn]));
                }
                set {
                    this[this.tableVenue.VenueNameColumn] = value;
                }
            }
            
            [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
            public string VenueDescription {
                get {
                    return ((string)(this[this.tableVenue.VenueDescriptionColumn]));
                }
                set {
                    this[this.tableVenue.VenueDescriptionColumn] = value;
                }
            }
            
            [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
            public string VenueStreet {
                get {
                    return ((string)(this[this.tableVenue.VenueStreetColumn]));
                }
                set {
                    this[this.tableVenue.VenueStreetColumn] = value;
                }
            }
            
            [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
            public string VenueCity {
                get {
                    return ((string)(this[this.tableVenue.VenueCityColumn]));
                }
                set {
                    this[this.tableVenue.VenueCityColumn] = value;
                }
            }
            
            [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
            public string VenueState {
                get {
                    return ((string)(this[this.tableVenue.VenueStateColumn]));
                }
                set {
                    this[this.tableVenue.VenueStateColumn] = value;
                }
            }
            
            [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
            public string VenuePostalCode {
                get {
                    return ((string)(this[this.tableVenue.VenuePostalCodeColumn]));
                }
                set {
                    this[this.tableVenue.VenuePostalCodeColumn] = value;
                }
            }
            
            [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
            public byte[] VenueGeographicMap {
                get {
                    return ((byte[])(this[this.tableVenue.VenueGeographicMapColumn]));
                }
                set {
                    this[this.tableVenue.VenueGeographicMapColumn] = value;
                }
            }
            
            [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
            public byte[] VenueFacilityMap {
                get {
                    return ((byte[])(this[this.tableVenue.VenueFacilityMapColumn]));
                }
                set {
                    this[this.tableVenue.VenueFacilityMapColumn] = value;
                }
            }
            
            [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
            public byte[] VenueImage {
                get {
                    return ((byte[])(this[this.tableVenue.VenueImageColumn]));
                }
                set {
                    this[this.tableVenue.VenueImageColumn] = value;
                }
            }
        }
        
        /// <summary>
        ///Row event argument class
        ///</summary>
        [global::System.CodeDom.Compiler.GeneratedCodeAttribute("System.Data.Design.TypedDataSetGenerator", "2.0.0.0")]
        public class VenueRowChangeEvent : global::System.EventArgs {
            
            private VenueRow eventRow;
            
            private global::System.Data.DataRowAction eventAction;
            
            [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
            public VenueRowChangeEvent(VenueRow row, global::System.Data.DataRowAction action) {
                this.eventRow = row;
                this.eventAction = action;
            }
            
            [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
            public VenueRow Row {
                get {
                    return this.eventRow;
                }
            }
            
            [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
            public global::System.Data.DataRowAction Action {
                get {
                    return this.eventAction;
                }
            }
        }
    }
}

#pragma warning restore 1591