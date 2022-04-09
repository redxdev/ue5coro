// Copyright © Laura Andelare
// All rights reserved.
// 
// Redistribution and use in source and binary forms, with or without
// modification, are permitted (subject to the limitations in the disclaimer
// below) provided that the following conditions are met:
// 
// 1. Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
// 
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
// 
// 3. Neither the name of the copyright holder nor the names of its
//    contributors may be used to endorse or promote products derived from
//    this software without specific prior written permission.
// 
// NO EXPRESS OR IMPLIED LICENSES TO ANY PARTY'S PATENT RIGHTS ARE GRANTED BY
// THIS LICENSE. THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
// CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT
// NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
// PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
// OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
// OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
// ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#pragma once

namespace UE5Coro::Latent
{
/**
 * Calls the provided callback on the game thread if this object is in scope
 * within a latent coroutine that's aborted by the latent action manager.<br>
 * Example usage:<br>
 * Latent::FOnActionAborted Guard([this]{cleanup code});
 * @see FPendingLatentAction::NotifyActionAborted()
 */
class UE5CORO_API FOnActionAborted
{
	TFunction<void()> Callback;

public:
	explicit FOnActionAborted(TFunction<void()> Callback);
	UE_NONCOPYABLE(FOnActionAborted);
	~FOnActionAborted();
};

/**
 * Calls the provided callback on the game thread if this object is in scope
 * within a latent coroutine whose object has been garbage collected.<br>
 * Example usage:<br>
 * Latent::FOnObjectDestroyed Guard([]{cleanup code});
 * @see FPendingLatentAction::NotifyObjectDestroyed()
 */
class UE5CORO_API FOnObjectDestroyed
{
	TFunction<void()> Callback;

public:
	explicit FOnObjectDestroyed(TFunction<void()> Callback);
	UE_NONCOPYABLE(FOnObjectDestroyed);
	~FOnObjectDestroyed();
};

class UE5CORO_API FOnActionAbortedOrDestroyed
{
	TFunction<void()> Callback;

public:
	explicit FOnActionAbortedOrDestroyed(TFunction<void()> Callback);
	UE_NONCOPYABLE(FOnActionAbortedOrDestroyed);
	~FOnActionAbortedOrDestroyed();
};
}
