using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

namespace ValidationMessage.Models
{
    public class Category
    {
        public int Id { get; set; }
        public string Name { get; set; }

        public DateTime CreateDateTime {  get; set; }

        public DateTime UpdateDateTime { get; set; } 
    }
}