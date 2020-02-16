<?php
/* Attempt MySQL server connection. Assuming you are running MySQL
server with default setting (user 'root' with no password) */
$link = mysqli_connect("localhost", "root", "", "pty");

// Check connection
if($link === false){
    die("ERROR: Could not connect. " . mysqli_connect_error());
}

   $name =$_GET['empViewSearch'];

// Attempt insert query execution
$sql = "SELECT * FROM Employee Where firstname ='$name'";

$ssn = $_GET['Ssn'];
$fname = $_GET['FirstName'];
$lname = $_GET['LastName'];
$salary = $_GET['Salary'];
$bdate = $_GET['bDate'];
$telno = $_GET['TelephoneNo'];
$sex = $_GET['Sex'];
$apt = $_GET['Apt_No'];
$street = $_GET['Street'];
$city = $_GET['City'];
$job = $_GET['Job Type'];
$work = $_GET['WorkedHours'];



if(mysqli_query($link, $sql)){
echo $fname;
  echo "Records inserted successfully.";
// header("Location: 'form1.html'");
//link('insert2.php','formp.html');
} else{
    echo "ERROR: Could not able to execute $sql. " . mysqli_error($link);
}

// Close connection
mysqli_close($link);
?>