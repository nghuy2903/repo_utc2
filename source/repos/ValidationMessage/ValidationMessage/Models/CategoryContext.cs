using System;
using System.Collections.Generic;
using System.Data.Entity;
using System.Linq;
using System.Web;

namespace ValidationMessage.Models
{
    public class CategoryContext : DbContecxt
    {
        public CategoryContext() : base("name = categoryContext")
        {

        }

        public virtual DbSet<Category> Categories { get; set; }

        //protected override void OnModelCreating(DbModelBuilder modelBuilder) { }
    }
}