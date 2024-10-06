/*code2.c*/ 
#include <stdio.h>

/* Function to convert Celsius to Fahrenheit*/
float celsius_to_fahrenheit(float celsius) {
    return (9.0/5.0) * celsius + 32;
}

/* Function to convert Celsius to Kelvin*/
float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

/* Function to convert Fahrenheit to Celsius*/
float fahrenheit_to_celsius(float fahrenheit) {
    return (5.0/9.0) * (fahrenheit - 32);
}


/* Function to convert Fahrenheit to Kelvin*/
float fahrenheit_to_kelvin(float fahrenheit) {
    return celsius_to_kelvin(fahrenheit_to_celsius(fahrenheit));
}

/* Function to convert Kelvin to Celsius*/
float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}

/* Function to convert Kelvin to Fahrenheit*/
float kelvin_to_fahrenheit(float kelvin) {
    return celsius_to_fahrenheit(kelvin_to_celsius(kelvin));
}

/* Function to categorize the temperature and provide a weather description */
void categorize_temperature(float celsius) {
    if (celsius < 0) {
        printf("Temperature category: Freezing\n");
        printf("Weather advisory: Stay indoors when possible.\n");
    } else if (celsius < 10) {
        printf("Temperature category: Cold\n");
        printf("Weather advisory: Wear a hoodie.\n");
    } else if (celsius < 25) {
        printf("Temperature category: Comfortable\n");
        printf("Weather advisory: You should feel comfortable.\n");
    } else if (celsius < 35) {
        printf("Temperature category: Hot\n");
        printf("Weather advisory: Stay hydrated.\n");
    } else {
        printf("Temperature category: Extreme Heat\n");
        printf("Weather advisory: Avoid outisde temps for periods of time.\n");
    }
}

int main() {
    float temperature;
    int current_scale, target_scale;

    printf("Enter the temperature: ");
    while (scanf("%f", &temperature) != 1) {
        printf("Invalid input. Please enter a valid temperature.\n");
        printf("Enter the temperature: ");
        
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    while (scanf("%d", &current_scale) != 1 || current_scale < 1 || current_scale > 3) {
        printf("Invalid input. Please choose a valid scale.\n");
        printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
       
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }/*User prompt for scale with edge cases*/

    printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    while (scanf("%d", &target_scale) != 1 || target_scale < 1 || target_scale > 3) {
        printf("Invalid input. Please choose a valid target scale.\n");
        printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
        
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    /* Check for large numbers*/
    if (temperature > 1000) {
        printf("Warning: Temperature is very large\n");
    }

    

    float converted_temperature;

    switch (current_scale) {
        case 1: /*Celsius*/
            switch (target_scale) {
                case 1: /*Celsius*/
                    converted_temperature = temperature;
                    break;
                case 2: /*Fahrenheit*/
                    converted_temperature = celsius_to_fahrenheit(temperature);
                    break;
                case 3: /*Kelvin*/
                    converted_temperature = celsius_to_kelvin(temperature);
                    break;
            }
            break;
        case 2: // Fahrenheit
            switch (target_scale) {
                case 1: /*Celsius*/
                    converted_temperature = fahrenheit_to_celsius(temperature);
                    break;
                case 2: /*Fahrenheit*/
                    converted_temperature = temperature;
                    break;
                case 3: /*Kelvin*/
                    converted_temperature = fahrenheit_to_kelvin(temperature);
                    break;
            }
            break;
        case 3: // Kelvin
            switch (target_scale) {
                case 1: /*Celsius*/
                    converted_temperature = kelvin_to_celsius(temperature);
                    break;
                case 2: /*Fahrenheit*/
                    converted_temperature = kelvin_to_fahrenheit(temperature);
                    break;
                case 3: /*Kelvin*/
                    converted_temperature = temperature;
                    break;
            }
            break;
    }

    printf("Converted temperature: ");
switch (target_scale) {
    case 1: /*Celsius*/
        printf("%.2f Celsius\n", converted_temperature);
        categorize_temperature(converted_temperature);
        break;
    case 2: /*Fahrenheit*/
        printf("%.2f Fahrenheit\n", converted_temperature);
        categorize_temperature(fahrenheit_to_celsius(converted_temperature));
        break;
    case 3: /*Kelvin*/
        printf("%.2f Kelvin\n", converted_temperature);
        categorize_temperature(kelvin_to_celsius(converted_temperature));
        break;
}

return 0; 
}