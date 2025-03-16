using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Web;

namespace ValidationMessage.Models
{
    public class Student
    {
        public int Id { get; set; } 

        [Required(ErrorMessage = "Name is required")]
        [StringLength(10, MinimumLength = 3, ErrorMessage = "Name must be between 3 and 10 characters")]
        public string Name { get; set; }

        [Required(ErrorMessage = "Age is required")]
        [Range(19, int.MaxValue, ErrorMessage = "Age must be greater than 18")]
        public int Age { get; set; }

        [Required(ErrorMessage = "Phone number is required")]
        [RegularExpression(@"^\d{10,11}$", ErrorMessage = "Phone number must contain only numbers and be between 8 and 9 digits")]
        public string PhoneNumber { get; set; }

        [Required(ErrorMessage = "Email is required")]
        [EmailAddress(ErrorMessage = "Invalid email format")]
        public string Email { get; set; }

        [Required(ErrorMessage = "Password is required")]
        public string Password { get; set; }

        [Compare("Password", ErrorMessage = "Confirm password must match the password")]
        public string ConfirmPassword { get; set; }

        [Required(ErrorMessage = "Gender is required")]
        public string Gender { get; set; }

        [Required(ErrorMessage = "Country is required")]
        public string Country { get; set; }

        public string Note { get; set; }

        public bool AcceptTerm {  get; set; }
    }
}