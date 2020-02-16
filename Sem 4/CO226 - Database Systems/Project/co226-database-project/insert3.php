

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
   $name10=$_GET['special'];


// Attempt insert query execution

$sql = "INSERT INTO Employee (firstName,lastName,telephoneNo,sex,apt_No,street,city,jobType) VALUES('$name1','$name2',$name6,'$name8',$name3,'$name4','$name5','$name9')";


if(mysqli_query($link, $sql)){


} else{
    echo "ERROR: Could not able to execute $sql. " . mysqli_error($link);
}


$fg = "SELECT MAX(ssn) AS wt FROM employee ";

$result = $link-> query($fg);
if($result->num_rows > 0){
	while($row = $result->fetch_assoc()){

	$tt = $row["wt"];



if($name9 == "Waiter"){
$fg = "INSERT INTO waiter (ssn) VALUES ($tt)";
   $rd = "UPDATE waiter SET no_of_tables = $name10 where ssn = $tt";
   $er = "UPDATE Employee SET salary = 30000 where ssn = $tt";
   break;
}

if($name9 == "Call Operator"){
   $fg = "INSERT INTO calloperator (ssn) VALUES ($tt)";
      $rd = "UPDATE calloperator SET startDate = '$name10' where ssn = $tt";
       $er = "UPDATE Employee SET salary = 35000 where ssn = $tt";
   break;
}

if($name9 == "Cashier"){
   $fg = "INSERT INTO cashier (ssn) VALUES ($tt)";
      $rd = "UPDATE cashier SET targeted_Customers = $name10 where ssn = $tt";
       $er = "UPDATE Employee SET salary = 40000 where ssn = $tt";
   break;
}

if($name9 == "Manager"){
$fg = "INSERT INTO manager (ssn) VALUES ($tt)";
   $rd = "UPDATE manager SET startDate = '$name10' where ssn = $tt";
    $er = "UPDATE Employee SET salary = 60000 where ssn = $tt";
   break;
}

if($name9 == "Cheif Chef"){
$fg = "INSERT INTO chifchef (ssn) VALUES ($tt)";
   $rd = "UPDATE chifchef SET numberOfChefs = $name10 where ssn = $tt";
    $er = "UPDATE Employee SET salary = 50000 where ssn = $tt";
   break;
}


if($name9 == "Chef"){
$fg = "INSERT INTO chef (ssn) VALUES ($tt)";
   $rd = "UPDATE chef SET chiefChefssn = $name10 where ssn = $tt";
    $er = "UPDATE Employee SET salary = 40000 where ssn = $tt";
  break;
}

if($name9 == "Delivery Boy"){
$fg = "INSERT INTO deliveryBoy (ssn) VALUES ($tt)";
   $rd = "UPDATE deliveryBoy SET no_of_delivers = $name10 where ssn = $tt";
   $er = "UPDATE Employee SET salary = 30000 where ssn = $tt";
   break;
}

if($name9 == "Cleaner"){
$fg = "INSERT INTO cleaner (ssn) VALUES ($tt)";
   $rd = "UPDATE cleaner SET working_area = '$name10' where ssn = $tt";
   $er = "UPDATE Employee SET salary = 20000 where ssn = $tt";
   break;
}



}
}

if(mysqli_query($link, $fg)){


} else{
    echo "ERROR: Could not able to execute $fg. " . mysqli_error($link);
}
if(mysqli_query($link, $rd)){


} else{
    echo "ERROR: Could not able to execute $rd. " . mysqli_error($link);
}
if(mysqli_query($link, $er)){


} else{
    echo "ERROR: Could not able to execute $er. " . mysqli_error($link);
}
// Close connection
mysqli_close($link);
?>

<html>
<body>

<style>
body{
   background-image: url(adult-african-agenda-1089556.jpg);
   background-size: cover;
   backgorund-position: center center;
   background-attachment: fixed;
   color:darkorange;

   }

</style>


<h1>You have inserted successfully...</h1>

<a href="empView.html">
<input type="button" name="Backtoapplication" value="Back to Employee View"></a>


</body>
</html>
