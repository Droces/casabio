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

class GradientBasedCorrShadows2012 extends AbstractTag
{

    protected $Id = 'GradientBasedCorrectionsLocalShadows2012';

    protected $Name = 'GradientBasedCorrShadows2012';

    protected $FullName = 'XMP::crs';

    protected $GroupName = 'XMP-crs';

    protected $g0 = 'XMP';

    protected $g1 = 'XMP-crs';

    protected $g2 = 'Image';

    protected $Type = 'real';

    protected $Writable = true;

    protected $Description = 'Gradient Based Corr Shadows 2012';

}
