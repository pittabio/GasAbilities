#pragma once

#define PRINT(DebugMessage, ...) {GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, FString::Printf(TEXT(DebugMessage), __VA_ARGS__)); }

#define SPHERE(Center) { if (GetWorld()) DrawDebugSphere(GetWorld(), Center, 20.f, 16, FColor::Blue, true); }
#define SPHERE_TICK(Center) { if (GetWorld()) DrawDebugSphere(GetWorld(), Center, 20.f, 16, FColor::Green, false); }

#define LINE(Start, End) { if (GetWorld()) DrawDebugLine(GetWorld(), Start, End, FColor::Blue, true); }
#define LINE_TICK(Start, End) { if (GetWorld()) DrawDebugLine(GetWorld(), Start, End, FColor::Green, false); }