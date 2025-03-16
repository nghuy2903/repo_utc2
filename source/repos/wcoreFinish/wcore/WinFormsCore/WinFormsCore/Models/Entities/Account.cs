using System;
using System.Collections.Generic;

namespace WinFormsCore.Models.Entities;

public partial class Account
{
    public int Id { get; set; }

    public string UserName { get; set; }

    public string Pass { get; set; }

    public string Fullname { get; set; }
}
