

<?php
/* Attempt MySQL server connection. Assuming you are running MySQL
server with default setting (user 'root' with no password) */
$link = mysqli_connect("localhost", "root", "", "database_project");

// Check connection
if($link === false){
    die("ERROR: Could not connect. " . mysqli_connect_error());
}
   $name1 =$_GET['menu_id'];
   $name2 =$_GET['Telephone'];
   $name3 =$_GET['firstName'];
   $name4 =$_GET['lastName'];
   $name5 =$_GET['apart_no'];
   $name6 =$_GET['street'];
   $name7 =$_GET['city'];
   $name8 =$_GET['cost'];
   $name9 =$_GET['empssn'];
   $name10 =$_GET['number'];


// Attempt insert query execution
$sql = "INSERT INTO Customers (menu_id,telephone_no,firstName,lastName,apt_no,street,city,cost,employee_ssn,Number_of_Items) VALUES($name1,$name2,'$name3','$name4',$name5,'$name6','$name7','$name8','$name9','$name10')";





if(mysqli_query($link, $sql)){


} else{
    echo "ERROR: Could not able to execute $sql. " . mysqli_error($link);
}

// Close connection
mysqli_close($link);
?>

<html>
<body>

<style>
body{
   background-image: url(blur-drinks-facial-expression-821054.jpg);
   background-size: cover;
   backgorund-position: center center;
   background-attachment: fixed;
   }

</style>


<h1>You have inserted successfully...</h1>

<br>
<br>
<br><br>

<a href="cusView.html">
<input type="button" name="Backtoapplication" value="Back to Customer View"></a>


</body>
</html>
