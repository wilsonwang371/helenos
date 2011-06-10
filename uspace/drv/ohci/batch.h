/*
 * Copyright (c) 2011 Jan Vesely
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * - Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 * - The name of the author may not be used to endorse or promote products
 *   derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/** @addtogroup drvusbohci
 * @{
 */
/** @file
 * @brief OHCI driver USB transaction structure
 */
#ifndef DRV_OHCI_BATCH_H
#define DRV_OHCI_BATCH_H

#include <usbhc_iface.h>
#include <usb/usb.h>
#include <usb/host/device_keeper.h>
#include <usb/host/endpoint.h>
#include <usb/host/batch.h>

usb_transfer_batch_t * batch_get(
    ddf_fun_t *fun, endpoint_t *ep, char *buffer, size_t size,
    const char *setup_buffer, size_t setup_size,
    usbhc_iface_transfer_in_callback_t func_in,
    usbhc_iface_transfer_out_callback_t func_out,
    void *arg);

bool batch_is_complete(usb_transfer_batch_t *instance);

void batch_commit(usb_transfer_batch_t *instance);

void batch_control_write(usb_transfer_batch_t *instance);

void batch_control_read(usb_transfer_batch_t *instance);

void batch_interrupt_in(usb_transfer_batch_t *instance);

void batch_interrupt_out(usb_transfer_batch_t *instance);

void batch_bulk_in(usb_transfer_batch_t *instance);

void batch_bulk_out(usb_transfer_batch_t *instance);
#endif
/**
 * @}
 */