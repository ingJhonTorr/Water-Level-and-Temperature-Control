<h1 align=center>Water Level and Temperature Control</h1> 
<p>This Arduino project uses sensors to monitor humidity and temperature. Depending on the humidity, it controls LEDs to indicate if a tank is full, medium, or almost empty. It also checks the temperature and activates a buzzer if it goes out of range. This code runs continuously to provide continuous environmental monitoring and feedback.</p>
<h2 align=center>Objective</h2>
<ul>
    <li>Implement a control system.</li>
    <li>Learn how to design digital circuits.</li>
    <li>Use the Arduino microcontroller to implement digital circuits.</li>
</ul>
<h2 align=center>Circuit ⚡</h2>
<div align=center><a href='https://postimages.org/' target='_blank'><img src='https://i.postimg.cc/RCy76D4F/Circuit.png' border='0' alt='Circuit'width="65%" height="65%"/></a></div>
<h2 align=center>Conditions</h2>
<p>Read the values from the humidity sensors (two of them) and the temperature sensor.</p>
<h3>Checking Humidity:</h3>
<ul>
    <li>If both humidity sensors detect high humidity (values greater than 50), it means the tank is full, so we turn on the green LED and display a message.</li>
    <li>If only the low humidity sensor detects humidity, it indicates that the tank is at a medium level. We blink the red LED and display a caution message.</li>
    <li>If neither sensor detects humidity, the tank is almost empty. We turn on the red LED and display a caution message.</li>
    <li>If only the high humidity sensor detects humidity, which should not happen, we indicate an error with both LEDs and display an error message.</li>
</ul>
<h3>Checking Temperature:</h3>
<ul>
    <li>If the temperature is above 30 degrees Celsius or below 15 degrees Celsius, activate the buzzer and display the temperature in Serial Monitor.</li>
</ul>

<h2 align=center>Solution</h2>
<ul>
    <li>Implement the circuit in Tinkercad.</li>
    <li>Copy the code from Arduino and paste it into Tinkercad.</li>
    <li>Verify that all humidity conditions are operating correctly.</li>
    <li>Make sure the buzzer is activated when the temperature goes outside the set range.</li>
</ul>
<h3>Congratulations, you did a great job!</h3>
