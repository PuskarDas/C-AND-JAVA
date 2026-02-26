const apiKey = "4be905eb73094ced844145926261501";
const searchBtn = document.getElementById("searchBtn");
const cityInput = document.getElementById("cityInput");
const weatherContent = document.getElementById("weatherContent");
const errorMsg = document.getElementById("error");

async function checkWeather(city) {
    const url = `https://api.weatherapi.com/v1/current.json?key=${apiKey}&q=${city}&aqi=yes`;

    try {
        const response = await fetch(url);
        
        if (!response.ok) {
            throw new Error("City not found");
        }

        const data = await response.json();

        // Update UI elements
        document.getElementById("cityName").innerText = `${data.location.name}, ${data.location.country}`;
        document.getElementById("dateTime").innerText = data.location.localtime;
        document.getElementById("temp").innerText = Math.round(data.current.temp_c) + "°C";
        document.getElementById("condition").innerText = data.current.condition.text;
        document.getElementById("weatherIcon").src = "https:" + data.current.condition.icon;
        document.getElementById("humidity").innerText = data.current.humidity + "%";
        document.getElementById("wind").innerText = data.current.wind_kph + " km/h";
        
        // AQI (US - EPA Standard Index)
        const aqiVal = data.current.air_quality["us-epa-index"];
        const aqiText = getAQIDesc(aqiVal);
        document.getElementById("aqi").innerText = `${aqiText} (${aqiVal})`;

        // Change background based on temp
        if(data.current.temp_c > 25) {
            document.body.style.background = "linear-gradient(135deg, #f83600, #fe8c00)";
        } else {
            document.body.style.background = "linear-gradient(135deg, #00b4db, #0083b0)";
        }

        weatherContent.style.display = "block";
        errorMsg.style.display = "none";

    } catch (error) {
        errorMsg.style.display = "block";
        weatherContent.style.display = "none";
    }
}

function getAQIDesc(idx) {
    const levels = {
        1: "Good",
        2: "Moderate",
        3: "Unhealthy (SG)",
        4: "Unhealthy",
        5: "Very Unhealthy",
        6: "Hazardous"
    };
    return levels[idx] || "N/A";
}

searchBtn.addEventListener("click", () => {
    if (cityInput.value.trim() !== "") {
        checkWeather(cityInput.value);
    }
});

// Allow pressing "Enter" to search
cityInput.addEventListener("keypress", (e) => {
    if (e.key === "Enter") {
        searchBtn.click();
    }
});