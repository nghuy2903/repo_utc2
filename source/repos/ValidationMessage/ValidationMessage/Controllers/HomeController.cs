using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Web;
using System.Web.Mvc;

namespace ValidationMessageDemo.Controllers
{
    public class HomeController : Controller
    {
        // GET: Home
        public ActionResult Index()
        {
            return View();
        }
        //[HttpPost]
        //public ActionResult Index(string Name, string Age, string PhoneNumber, string Email, string Password, string ConfirmPassword, string Gender, string Country, string Note, bool AcceptTerm)
        //{
        //    if (Name.Equals("") == true)
        //        ModelState.AddModelError("Name", "Name is required !");
        //    ViewData["NameError"] = "*";
        //    if (Age.Equals("") == true)
        //        ModelState.AddModelError("Age", "Age is required !");
        //    ViewData["AgeError"] = "*";
        //    if (PhoneNumber.Equals("") == true)
        //        ModelState.AddModelError("PhoneNumber", "PhoneNumber is required !");
        //    ViewData["PhoneNumberError"] = "*";
        //    if (Email.Equals("") == true)
        //        ModelState.AddModelError("Email", "Email is required !");
        //    ViewData["EmailError"] = "*";
        //    if (Password.Equals("") == true)
        //        ModelState.AddModelError("Password", "Password is required !");
        //    ViewData["PasswordError"] = "*";
        //    if (ConfirmPassword.Equals("") == true)
        //        ModelState.AddModelError("ConfirmPassword", "ConfirmPassword is required !");
        //    ViewData["ConfirmPasswordError"] = "*";
        //    if (string.IsNullOrWhiteSpace(Gender))
        //        ModelState.AddModelError("Gender", "Gender is required !");
        //    ViewData["GenderError"] = "*";
        //    if (Country.Equals("") == true)
        //        ModelState.AddModelError("Country", "Country is required !");
        //    ViewData["CountryError"] = "*";


        //    if (Note.Equals("") == true)
        //        ModelState.AddModelError("Note", "Note is required !");
        //    ViewData["NoteError"] = "*";


        //    if (AcceptTerm != true)
        //        ModelState.AddModelError("AcceptTerm", "AcceptTerm is required !");
        //    ViewData["AcceptTermError"] = "*";
        //    if (ModelState.IsValid == true)
        //    {
        //        ViewData["SuccessMessage"] = "<script>alert('Data has been Submitted successfully !')</script>";
        //    }


        //    return View();
        //}

        
    }
}