
<?php

	$link = mysqli_connect("localhost", "root", "", "database_project");

	// Check connection
	if($link === false){
	    die("ERROR: Could not connect. " . mysqli_connect_error());
	}


if(isset($_POST['yn'])){
		$user = $_POST['md'];

			$sql = "SELECT Availability FROM Menu WHERE menu_id = $user";





$result = $link-> query($sql);
if($result->num_rows > 0){
while($row = $result->fetch_assoc()){


if($row["Availability"] == "YES"){
	$pass = "Available";
}else{
	$pass = "Not Available";
}
}
}
if(mysqli_query($link, $sql)){

} else{
    echo "ERROR: Could not able to execute $sql. " . mysqli_error($link);
}
}
	mysqli_close($link);
?>

















<html>
<head>
 <link rel="stylesheet" type="text/css" href="hello.css">

<style>


div.gallery {
  margin: 5px;
  border: 1px solid #ccc;
  float: left;
  width: 250px;
}

div.gallery:hover {
  border: 1px solid #777;
}

div.gallery img {
  width: 100%;
  height: 250px;
}

div.desc {
  padding: 15px;
  text-align: center;
}
.button {
  background-color: #4CAF50; /* Green */
  border: none;
  color: white;
  padding: 20px;
  text-align: center;
  text-decoration: none;
  display: inline-block;
  font-size: 16px;
  margin: 4px 2px;
  cursor: pointer;
}

.button1 {border-radius: 2px;}
.button2 {border-radius: 4px;}
.button3 {border-radius: 8px;}
.button4 {border-radius: 12px;}
.button5 {border-radius: 50%;}

</style>
</head>

<body>


<link rel="stylesheet" href="css1/update.css">


<div class="col-lg-2">
<label>SEARCH BY:</label>
<form class="form-group" action="foodsNew.php" method = "POST" id = "myform">
	<input type="text" name="md" id = "md" class="form-control" placeholder="Your item id here..." value = "<?php echo @$user; ?>"><br>
	<input type="text" name="yn" id="yn" class="form-control" placeholder="Availability" value = "<?php echo @$pass; ?>"><br>

	<input type="submit" name="foodSearch" value="SEARCH" class="btn btn-primary btn-block btn-lg">

	<input class = "button button2" type = "button" onclick = "myFunction()" value = "Reset">


</form>
</div>

<script>
	function myFunction(){
		document.getElementById("md").value = '';
		document.getElementById("yn").value = '';
	}
</script>
<br><br><br> <br><br><br><br><br><br><br>
<H1><br><br><br>FRIED RICE AND BIRYANI</H1><br>


<div class="gallery">

    <img src="menuImages/chikenbriyani.png" width="300" height="200">

  <div class="desc">Chicken Biryani</div>
  <div class="desc">Rs 470.00</div>
  <div class="desc">Item Id: 100</div>

  <a target="_blank" href="cusDetails.html">
  <input type="submit" name="bt2" value="BUY NOW" class = "button">
  </a>
</div>


<div class="gallery">

    <img src="menuImages/Prawn_Fried_Rice_Recipe_-_Chinese_Fried_Rice_With_Prawns-1.jpg" alt="Forest" width="300" height="200">

  <div class="desc">Prawn Rice</div>
  <div class="desc">Rs 500.00</div>
  <div class="desc">Item Id: 101</div>

  <a target="_blank" href="cusDetails.html">
  <input type="submit" name="bt4" value="BUY NOW" class = "button">
  </a>
</div>


<div class="gallery">

    <img src="menuImages/kathy-fang-shrimp-fried-rice-today-170718_8bd70dd947e874b5be98988346a784c5.jpg" alt="Northern Lights" width="300" height="200">

  <div class="desc">Shrimp Fried Rice</div>
  <div class="desc">Rs 540.00</div>
  <div class="desc">Item Id: 102</div>

  <a target="_blank" href="cusDetails.html">
  <input type="submit" name="bt6" value="BUY NOW" class = "button">
  </a>
</div>

<div class="gallery">
    <img src="menuImages/Indonesian-Fried-Rice-square.jpg" alt="Mountains" width="300" height="200">

  <div class="desc">Chinese Fried Rice</div>
  <div class="desc">Rs 350.00</div>
  <div class="desc">Item Id: 103</div>


  <a target="_blank" href="cusDetails.html">
  <input type="submit" name="bt8" value="BUY NOW" class = "button">
  </a>
</div>

<div class="gallery">
    <img src="menuImages/roast-miso-mushrooms-with-gai-lan-36134-4.jpg" alt="Mountains" width="300" height="200">

  <div class="desc">Roast Mushrooms & Gai Lan</div>
  <div class="desc">Rs 600.00</div>
	<div class="desc">Item Id: 104</div>


  <a target="_blank" href="cusDetails.html">
  <input type="submit" name="bt8" value="BUY NOW" class = "button">
  </a>
</div>



<div class="gallery">
    <img src="menuImages/nasi-goreng1.jpg" alt="Mountains" width="300" height="200">

  <div class="desc">Nasi Goreng</div>
  <div class="desc">Rs 500.00</div>
  <div class="desc">Item Id: 105</div>


  <a target="_blank" href="cusDetails.html">
  <input type="submit" name="bt8" value="BUY NOW" class = "button">

  </a>

</div>
 <br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br> <br><br><br><br><br><br><br>
 <br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br> <br><br><br><br><br><br><br>
<H1>SALADS</H1><br>

<div class="gallery">
    <img src="menuImages/ImageHandler.jpg" alt="Mountains" width="300" height="200">

  <div class="desc">Prawn salad</div>
  <div class="desc">Rs 300.00</div>
  <div class="desc">Item Id: 106</div>


  <a target="_blank" href="cusDetails.html">
  <input type="submit" name="bt8" value="BUY NOW" class = "button">
  </a>
</div>

<div class="gallery">
    <img src="menuImages/los-poblanos-historic-inn-best-breakfast-america-FT-BLOG1118.jpg" alt="Mountains" width="300" height="200">

  <div class="desc">Cheese Vegi</div>
  <div class="desc">RS 175.00</div>
  <div class="desc">Item Id: 107</div>


  <a target="_blank" href="cusDetails.html">
  <input type="submit" name="bt8" value="BUY NOW" class = "button">
  </a>
</div>

<div class="gallery">
    <img src="menuImages/cauliflower-salad-with-yogurt-sauce-and-pomegranate-xl-MAG1218_0.jpg" alt="Mountains" width="300" height="200">

  <div class="desc">Cauliflower Salad</div>
  <div class="desc">Rs 350.00</div>
  <div class="desc">Item Id: 108</div>

  <a target="_blank" href="cusDetails.html">
  <input type="submit" name="bt8" value="BUY NOW" class = "button">
  </a>
</div>

<div class="gallery">
    <img src="menuImages/Skinny-Taco-Salad-recipe.jpg" alt="Mountains" width="300" height="200">

  <div class="desc">Skinny Taco Salad</div>
  <div class="desc">Rs 300.00</div>
  <div class="desc">Item Id: 109</div>

  <a target="_blank" href="cusDetails.html">
  <input type="submit" name="bt8" value="BUY NOW" class = "button">
  </a>
</div>

<div class="gallery">
    <img src="menuImages/Caribbean-garden-salad-6.jpg" alt="Mountains" width="300" height="200">

  <div class="desc">Caribbean Garden</div>
  <div class="desc">Rs  350.00</div>
  <div class="desc">Item Id: 110</div>


  <a target="_blank" href="cusDetails.html">
  <input type="submit" name="bt8" value="BUY NOW" class = "button">
  </a>
</div>



<div class="gallery">
    <img src="menuImages/Quinoa-Vegetable-Bowl-Salad-3.jpg" alt="Mountains" width="300" height="200">

  <div class="desc">Quino Vegetable Salad</div>
  <div class="desc">Rs 300.00</div>
  <div class="desc">Item Id: 111</div>


  <a target="_blank" href="cusDetails.html">
  <input type="submit" name="bt8" value="BUY NOW" class = "button">
  </a>
</div>

<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br> <br><br><br><br><br><br><br>
<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br> <br><br><br><br><br><br><br>
<H1>DESSERTS</H1><br>

<div class="gallery">
    <img src="menuImages/whitechocolate cake.jpg" alt="Mountains" width="300" height="200">

  <div class="desc">White Choc Cake</div>
  <div class="desc">Rs 100.00</div>
  <div class="desc">Item Id: 112</div>


  <a target="_blank" href="cusDetails.html">
  <input type="submit" name="bt8" value="BUY NOW" class = "button">
  </a>
</div>

<div class="gallery">
    <img src="menuImages/peanutsandwidch.png" alt="Mountains" width="300" height="200">

  <div class="desc">Peaunut Sandwich</div>
  <div class="desc">RS 125.00</div>
  <div class="desc">Item Id: 113</div>

  <a target="_blank" href="cusDetails.html">
  <input type="submit" name="bt8" value="BUY NOW" class = "button">
  </a>
</div>

<div class="gallery">
    <img src="menuImages/Chocolate-Pudding-Trifle-square-no-wm.jpg" alt="Mountains" width="300" height="200">

  <div class="desc">Chocolate Pudding</div>
  <div class="desc">Rs 200.00</div>
  <div class="desc">Item Id: 114</div>

  <a target="_blank" href="cusDetails.html">
  <input type="submit" name="bt8" value="BUY NOW" class = "button">
  </a>
</div>

<div class="gallery">
    <img src="menuImages/imagesRO17GF14.jpg" alt="Mountains" width="300" height="200">

  <div class="desc">Ribbon Sandwich</div>
  <div class="desc">Rs 70.00</div>
  <div class="desc">Item Id: 115</div>


  <a target="_blank" href="cusDetails.html">
  <input type="submit" name="bt8" value="BUY NOW" class = "button">
  </a>
</div>

<div class="gallery">
    <img src="menuImages/farro-pudding.jpg" alt="Mountains" width="300" height="200">

  <div class="desc">farro pudding</div>
  <div class="desc">Rs  150.00</div>
  <div class="desc">Item Id: 116</div>


  <a target="_blank" href="cusDetails.html">
  <input type="submit" name="bt8" value="BUY NOW" class = "button">
  </a>
</div>



<div class="gallery">
    <img src="menuImages/BERRYPUDDING.jpg" alt="Mountains" width="300" height="200">

  <div class="desc">Berry Pudding</div>
  <div class="desc">Rs 300.00</div>
  <div class="desc">Item Id: 117</div>

  <a target="_blank" href="cusDetails.html">
  <input type="submit" name="bt8" value="BUY NOW" class = "button">
  </a>
</div>

<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br> <br><br><br><br><br><br><br>
<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br> <br><br><br><br><br><br><br>
<H1>BEVERAGES</H1><br>

<div class="gallery">
    <img src="menuImages/mango.png" alt="Mountains" width="300" height="200">

  <div class="desc">Mango Juice</div>
  <div class="desc">Rs 300.00</div>
  <div class="desc">Item Id: 118</div>


  <a target="_blank" href="cusDetails.html">
  <input type="submit" name="bt8" value="BUY NOW" class = "button">
  </a>
</div>

<div class="gallery">
    <img src="menuImages/orange.jpg" alt="Mountains" width="300" height="200">

  <div class="desc">Orange Juice</div>
  <div class="desc">RS 300.00</div>
  <div class="desc">Item Id: 119</div>

  <a target="_blank" href="cusDetails.html">
  <input type="submit" name="bt8" value="BUY NOW" class = "button">
  </a>
</div>

<div class="gallery">
    <img src="menuImages/How-to-Cut-a-Pomegranate-FF.jpg" alt="Mountains" width="300" height="200">

  <div class="desc">Pomegranate Juice</div>
  <div class="desc">Rs 400.00</div>
  <div class="desc">Item Id: 120</div>

  <a target="_blank" href="cusDetails.html">
  <input type="submit" name="bt8" value="BUY NOW" class = "button">
  </a>
</div>

<div class="gallery">
    <img src="menuImages/Mint-Cookie-Cocktail-350x460.jpg" alt="Mountains" width="300" height="200">

  <div class="desc">Mint Cookie Cocktail </div>
  <div class="desc">Rs 470.00</div>
  <div class="desc">Item Id: 121</div>


  <a target="_blank" href="cusDetails.html">
  <input type="submit" name="bt8" value="BUY NOW" class = "button">
  </a>
</div>

<div class="gallery">
    <img src="menuImages/P7191662-1.jpg" alt="Mountains" width="300" height="200">

  <div class="desc">Faluda</div>
  <div class="desc">Rs  350.00</div>
  <div class="desc">Item Id: 122</div>


  <a target="_blank" href="cusDetails.html">
  <input type="submit" name="bt8" value="BUY NOW" class = "button">
  </a>
</div>



<div class="gallery">
    <img src="menuImages/suvava.jpg" alt="Mountains" width="300" height="200">

  <div class="desc">Suvava</div>
  <div class="desc">Rs 300.00</div>
  <div class="desc">Item Id: 123</div>


  <a target="_blank" href="cusDetails.html">
  <input type="submit" name="bt8" value="BUY NOW" class = "button">
  </a>
</div>

<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br> <br><br><br><br><br><br><br>
<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br> <br><br><br><br><br><br><br>
<H1>NOODLES</H1><br>

<div class="gallery">
    <img src="menuImages/prawn-and-rice-noodles-87689-1.jpg" alt="Mountains" width="300" height="200">

  <div class="desc">Prawn & Rice noodles</div>
  <div class="desc">Rs 600.00</div>
  <div class="desc">Item Id: 124</div>


  <a target="_blank" href="cusDetails.html">
  <input type="submit" name="bt8" value="BUY NOW" class = "button">
  </a>
</div>

<div class="gallery">
    <img src="menuImages/prawn-cucumber-noodles.jpg" alt="Mountains" width="300" height="200">

  <div class="desc">Prawn cucumber noodles</div>
  <div class="desc">RS 600.00</div>
  <div class="desc">Item Id: 125</div>


  <a target="_blank" href="cusDetails.html">
  <input type="submit" name="bt8" value="BUY NOW" class = "button">
  </a>
</div>

<div class="gallery">
    <img src="menuImages/Thai-peanut-sauce-noodles-and-chicken-ohsweetbasil.com_.jpg" alt="Mountains" width="300" height="200">

  <div class="desc">Peanut sauce noodles</div>
  <div class="desc">Rs 400.00</div>
  <div class="desc">Item Id: 126</div>


  <a target="_blank" href="cusDetails.html">
  <input type="submit" name="bt8" value="BUY NOW" class = "button">
  </a>
</div>

<div class="gallery">
    <img src="menuImages/thai-peanut-sweet-potato-noodles-3" alt="Mountains" width="300" height="200">

  <div class="desc">peanut sweet noodles </div>
  <div class="desc">Rs 770.00</div>
  <div class="desc">Item Id: 127</div>

  <a target="_blank" href="cusDetails.html">
  <input type="submit" name="bt8" value="BUY NOW" class = "button">
  </a>
</div>

<div class="gallery">
    <img src="menuImages/imagesLGL8FMS7.jpg" alt="Mountains" width="300" height="200">

  <div class="desc">Tofua</div>
  <div class="desc">Rs  750.00</div>
  <div class="desc">Item Id: 128</div>


  <a target="_blank" href="cusDetails.html">
  <input type="submit" name="bt8" value="BUY NOW" class = "button">
  </a>
</div>



<div class="gallery">
    <img src="menuImages/DSCF5215.jpg" alt="Mountains" width="300" height="200">

  <div class="desc">Mix noodles</div>
  <div class="desc">Rs 500.00</div>
  <div class="desc">Item Id: 129</div>


  <a target="_blank" href="cusDetails.html">
  <input type="submit" name="bt8" value="BUY NOW" class = "button">
  </a>
</div>

 <br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br> <br><br><br><br><br><br><br>
 <br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br> <br><br><br><br><br><br><br>
<H1>SOUPS</H1><br>

<div class="gallery">
    <img src="menuImages/imagesYKJ0799H.jpg" alt="Mountains" width="300" height="200">

  <div class="desc">Chicken soup</div>
  <div class="desc">Rs 500.00</div>
  <div class="desc">Item Id: 130</div>


  <a target="_blank" href="cusDetails.html">
  <input type="submit" name="bt8" value="BUY NOW" class = "button">
  </a>
</div>

<div class="gallery">
    <img src="menuImages/imagesXGK0DXG1.jpg" alt="Mountains" width="300" height="200">

  <div class="desc">Potato Cream Soup</div>
  <div class="desc">RS 400.00</div>
  <div class="desc">Item Id: 131</div>


  <a target="_blank" href="cusDetails.html">
  <input type="submit" name="bt8" value="BUY NOW" class = "button">
  </a>
</div>

<div class="gallery">
    <img src="menuImages/untitlend.png" alt="Mountains" width="300" height="200">

  <div class="desc">Spicy Lentil Soup</div>
  <div class="desc">Rs 400.00</div>
  <div class="desc">Item Id: 132</div>


  <a target="_blank" href="cusDetails.html">
  <input type="submit" name="bt8" value="BUY NOW" class = "button">
  </a>
</div>

<div class="gallery">
    <img src="menuImages/untitleld.png" alt="Mountains" width="300" height="200">

  <div class="desc">Spinach Soup </div>
  <div class="desc">Rs 370.00</div>
  <div class="desc">Item Id: 133</div>


  <a target="_blank" href="cusDetails.html">
  <input type="submit" name="bt8" value="BUY NOW" class = "button">
  </a>
</div>

<div class="gallery">
    <img src="menuImages/vuntitled.png" alt="Mountains" width="300" height="200">

  <div class="desc">Vegetable Soup</div>
  <div class="desc">Rs  250.00</div>
  <div class="desc">Item Id: 134</div>


  <a target="_blank" href="cusDetails.html">
  <input type="submit" name="bt8" value="BUY NOW" class = "button">
  </a>
</div>



<div class="gallery">
    <img src="menuImages/imagesBS1TCW4D.jpg" alt="Mountains" width="300" height="200">

  <div class="desc">Cream Chicken Soup</div>
  <div class="desc">Rs 500.00</div>
  <div class="desc">Item Id: 135</div>


  <a target="_blank" href="cusDetails.html">
  <input type="submit" name="bt8" value="BUY NOW" class = "button">
  </a>
</div>

<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br> <br><br><br><br><br><br><br>
<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br> <br><br><br><br><br><br><br>
<H1>HOT DRINKS</H1><br>

<div class="gallery">
    <img src="menuImages/imagesPJP7XH1P.jpg" alt="Mountains" width="300" height="200">

  <div class="desc">Masala Tea</div>
  <div class="desc">Rs 100.00</div>
  <div class="desc">Item Id: 136</div>


  <a target="_blank" href="cusDetails.html">
  <input type="submit" name="bt8" value="BUY NOW" class = "button">
  </a>
</div>

<div class="gallery">
    <img src="menuImages/untitlred.png" alt="Mountains" width="300" height="200">

  <div class="desc">Cinnomon Tea</div>
  <div class="desc">RS 150.00</div>
  <div class="desc">Item Id: 137</div>


  <a target="_blank" href="cusDetails.html">
  <input type="submit" name="bt8" value="BUY NOW" class = "button">
  </a>
</div>

<div class="gallery">
    <img src="menuImages/untitlmed.png" alt="Mountains" width="300" height="200">

  <div class="desc">Coffe</div>
  <div class="desc">Rs 100.00</div>
  <div class="desc">Item Id: 138</div>


  <a target="_blank" href="cusDetails.html">
  <input type="submit" name="bt8" value="BUY NOW" class = "button">
  </a>
</div>

<div class="gallery">
    <img src="menuImages/untqitled.png" alt="Mountains" width="300" height="200">

  <div class="desc">Hot Chocolate </div>
  <div class="desc">Rs 400.00</div>
  <div class="desc">Item Id: 139</div>


  <a target="_blank" href="cusDetails.html">
  <input type="submit" name="bt8" value="BUY NOW" class = "button">
  </a>
</div>

<div class="gallery">
    <img src="menuImages/untintled.png" alt="Mountains" width="300" height="200">

  <div class="desc">Lime Tea</div>
  <div class="desc">Rs  100.00</div>
  <div class="desc">Item Id: 140</div>


  <a target="_blank" href="cusDetails.html">
  <input type="submit" name="bt8" value="BUY NOW" class = "button">
  </a>
</div>



<div class="gallery">
    <img src="menuImages/untibtled.png" alt="Mountains" width="300" height="200">

  <div class="desc">Ginger Lime Tea</div>
  <div class="desc">Rs 100.00</div>
  <div class="desc">Item Id: 141</div>


  <a target="_blank" href="cusDetails.html">
  <input type="submit" name="bt8" value="BUY NOW" class = "button">
  </a>
</div>
</body>
</html>
