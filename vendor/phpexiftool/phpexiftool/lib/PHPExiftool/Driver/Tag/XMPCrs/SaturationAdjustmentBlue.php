<?php

/*
 * This file is part of PHPExifTool.
 *
 * (c) 2012 Romain Neutron <imprec@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPExiftool\Driver\Tag\XMPCrs;

use PHPExiftool\Driver\AbstractTag;

class SaturationAdjustmentBlue extends AbstractTag
{

    protected $Id = 'SaturationAdjustmentBlue';

    protected $Name = 'SaturationAdjustmentBlue';

    protected $FullName = 'XMP::crs';

    protected $GroupName = 'XMP-crs';

    protected $g0 = 'XMP';

    protected $g1 = 'XMP-crs';

    protected $g2 = 'Image';

    protected $Type = 'integer';

    protected $Writable = true;

    protected $Description = 'Saturation Adjustment Blue';

}