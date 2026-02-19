# PowerShell script for testing the base converter

Write-Host ""
Write-Host "========== Base Converter Test =========="
Write-Host ""

# Test values
$test_values = @(5, -5, 255, -128, 1024, 0, 127)

foreach ($value in $test_values) {
    Write-Host "Testing: $value" -ForegroundColor Cyan
    
    # Create input pipe
    $process = @"
$value
4
"@ | ForEach-Object { [IO.File]::WriteAllText('temp_input.txt', $_) }
    
    Write-Host "---"
}

Write-Host ""
Write-Host "For interactive testing, run: .\bin\converter.exe"
