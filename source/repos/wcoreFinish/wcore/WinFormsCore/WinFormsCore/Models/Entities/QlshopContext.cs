using System;
using System.Collections.Generic;
using Microsoft.EntityFrameworkCore;

namespace WinFormsCore.Models.Entities;

public partial class QlshopContext : DbContext
{
    public QlshopContext()
    {
    }

    public QlshopContext(DbContextOptions<QlshopContext> options)
        : base(options)
    {
    }

    public virtual DbSet<Account> Accounts { get; set; }

    public virtual DbSet<Customer> Customers { get; set; }

    public virtual DbSet<Order> Orders { get; set; }

    public virtual DbSet<OrderItem> OrderItems { get; set; }

    public virtual DbSet<Product> Products { get; set; }

    public virtual DbSet<Province> Provinces { get; set; }

    public virtual DbSet<Supplier> Suppliers { get; set; }

    protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
#warning To protect potentially sensitive information in your connection string, you should move it out of source code. You can avoid scaffolding the connection string by using the Name= syntax to read it from configuration - see https://go.microsoft.com/fwlink/?linkid=2131148. For more guidance on storing connection strings, see https://go.microsoft.com/fwlink/?LinkId=723263.
        => optionsBuilder.UseSqlServer("Data Source=DESKTOP-H7A65TB;Initial Catalog=QLShop;Integrated Security=True;TrustServerCertificate=True");

    protected override void OnModelCreating(ModelBuilder modelBuilder)
    {
        modelBuilder.Entity<Account>(entity =>
        {
            entity.HasKey(e => e.Id).HasName("PK__ACCOUNT__3214EC271AB52A50");

            entity.ToTable("ACCOUNT");

            entity.Property(e => e.Id).HasColumnName("ID");
            entity.Property(e => e.Fullname)
                .HasMaxLength(40)
                .IsUnicode(false)
                .IsFixedLength();
            entity.Property(e => e.Pass)
                .IsRequired()
                .HasMaxLength(20)
                .IsUnicode(false)
                .IsFixedLength();
            entity.Property(e => e.UserName)
                .IsRequired()
                .HasMaxLength(20)
                .IsUnicode(false)
                .IsFixedLength();
        });

        modelBuilder.Entity<Customer>(entity =>
        {
            entity.HasKey(e => e.Id).HasName("PK_CUSTOMER");

            entity.ToTable("Customer");

            entity.HasIndex(e => new { e.LastName, e.FirstName }, "IndexCustomerName");

            entity.Property(e => e.City).HasMaxLength(40);
            entity.Property(e => e.Country).HasMaxLength(40);
            entity.Property(e => e.FirstName)
                .IsRequired()
                .HasMaxLength(40);
            entity.Property(e => e.LastName)
                .IsRequired()
                .HasMaxLength(40);
            entity.Property(e => e.Phone).HasMaxLength(20);
        });

        modelBuilder.Entity<Order>(entity =>
        {
            entity.HasKey(e => e.Id).HasName("PK_ORDER");

            entity.ToTable("Order");

            entity.HasIndex(e => e.CustomerId, "IndexOrderCustomerId");

            entity.HasIndex(e => e.OrderDate, "IndexOrderOrderDate");

            entity.Property(e => e.OrderDate)
                .HasDefaultValueSql("(getdate())")
                .HasColumnType("datetime");
            entity.Property(e => e.OrderNumber).HasMaxLength(10);
            entity.Property(e => e.TotalAmount)
                .HasDefaultValue(0m)
                .HasColumnType("decimal(12, 2)");

            entity.HasOne(d => d.Customer).WithMany(p => p.Orders)
                .HasForeignKey(d => d.CustomerId)
                .OnDelete(DeleteBehavior.ClientSetNull)
                .HasConstraintName("FK_ORDER_REFERENCE_CUSTOMER");
        });

        modelBuilder.Entity<OrderItem>(entity =>
        {
            entity.HasKey(e => e.Id).HasName("PK_ORDERITEM");

            entity.ToTable("OrderItem");

            entity.HasIndex(e => e.OrderId, "IndexOrderItemOrderId");

            entity.HasIndex(e => e.ProductId, "IndexOrderItemProductId");

            entity.Property(e => e.Quantity).HasDefaultValue(1);
            entity.Property(e => e.UnitPrice).HasColumnType("decimal(12, 2)");

            entity.HasOne(d => d.Order).WithMany(p => p.OrderItems)
                .HasForeignKey(d => d.OrderId)
                .OnDelete(DeleteBehavior.ClientSetNull)
                .HasConstraintName("FK_ORDERITE_REFERENCE_ORDER");

            entity.HasOne(d => d.Product).WithMany(p => p.OrderItems)
                .HasForeignKey(d => d.ProductId)
                .OnDelete(DeleteBehavior.ClientSetNull)
                .HasConstraintName("FK_ORDERITE_REFERENCE_PRODUCT");
        });

        modelBuilder.Entity<Product>(entity =>
        {
            entity.HasKey(e => e.Id).HasName("PK_PRODUCT");

            entity.ToTable("Product");

            entity.HasIndex(e => e.ProductName, "IndexProductName");

            entity.HasIndex(e => e.SupplierId, "IndexProductSupplierId");

            entity.Property(e => e.Package).HasMaxLength(30);
            entity.Property(e => e.ProductName)
                .IsRequired()
                .HasMaxLength(50);
            entity.Property(e => e.UnitPrice)
                .HasDefaultValue(0m)
                .HasColumnType("decimal(12, 2)");

            entity.HasOne(d => d.Supplier).WithMany(p => p.Products)
                .HasForeignKey(d => d.SupplierId)
                .OnDelete(DeleteBehavior.ClientSetNull)
                .HasConstraintName("FK_PRODUCT_REFERENCE_SUPPLIER");
        });

        modelBuilder.Entity<Province>(entity =>
        {
            entity.HasKey(e => e.ProvinceId).HasName("PK__Province__FD0A6FA3E9A0864E");

            entity.ToTable("Province");

            entity.Property(e => e.ProvinceId).HasColumnName("ProvinceID");
            entity.Property(e => e.ProvinceName)
                .IsRequired()
                .HasMaxLength(100);
        });

        modelBuilder.Entity<Supplier>(entity =>
        {
            entity.HasKey(e => e.Id).HasName("PK_SUPPLIER");

            entity.ToTable("Supplier");

            entity.HasIndex(e => e.Country, "IndexSupplierCountry");

            entity.HasIndex(e => e.CompanyName, "IndexSupplierName");

            entity.Property(e => e.City).HasMaxLength(40);
            entity.Property(e => e.CompanyName)
                .IsRequired()
                .HasMaxLength(40);
            entity.Property(e => e.ContactName).HasMaxLength(50);
            entity.Property(e => e.ContactTitle).HasMaxLength(40);
            entity.Property(e => e.Country).HasMaxLength(40);
            entity.Property(e => e.Fax).HasMaxLength(30);
            entity.Property(e => e.Phone).HasMaxLength(30);
        });

        OnModelCreatingPartial(modelBuilder);
    }

    partial void OnModelCreatingPartial(ModelBuilder modelBuilder);
}
