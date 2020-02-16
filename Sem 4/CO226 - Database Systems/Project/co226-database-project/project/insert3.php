

<?php
/* Attempt MySQL server connection. Assuming you are running MySQL
server with default setting (user 'root' with no password) */
$link = mysqli_connect("localhost", "root", "", "database_project");

// Check connection
if($link === false){
    die("ERROR: Could not connect. " . mysqli_connect_error());
}
   $name1 =$_GET['fname'];
   $name2 =$_GET['lname'];
   $name3 =$_GET['apt'];
   $name4 =$_GET['street'];
   $name5 =$_GET['city'];
   $name6 =$_GET['Telphone'];
  $name8 =$_GET['gender'];
   $name9 =$_GET['position'];


// Attempt insert query execution
$sql = "INSERT INTO Employee (firstName,lastName,telephoneNo,sex,apt_No,street,city,jobType) VALUES('$name1','$name2',$name6,'$name8',$name3,'$name4','$name5','$name9')";





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
   background-image: url(vintage-restaurant-background-vector-2015967.jpg);
   background-size: cover;
   backgorund-position: center center;
   background-attachment: fixed;
   }

</style>


<h1>You have inserted successfully...</h1>

<a href="empView.html">
<input type="button" name="Backtoapplication" value="Back to Employee View"></a>


</body>
</html>
